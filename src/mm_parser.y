%{
/*
MathMachine
Copyright (C) 2009-2011 Dr.Kameleon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*//*

MM_PARSER.Y

*/

#include "mathmachine.h"
#include <stdio.h>
#include <string.h>

void yyerror(const char *str)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", yycolumn, "^", yycolumn, str);
}
 
int yywrap()
{
	return 1;
}
%}

%union 
{
	char* str;
	mm_st_exec*			_st_exec;
	mm_st_use* 			_st_use;
	mm_st_set*			_st_set;
	mm_st_ret* 			_st_ret;
	mm_st_let*			_st_let;
	mm_st_get*			_st_get;
	mm_st_loop* 			_st_loop;
	mm_st_if*			_st_if;
	mm_st_put*			_st_put;
	mm_st_save*			_st_save;
	mm_condition*			_condition;
	mm_argument*			_argument;
	mm_function_call*		_function_call;
	mm_expression_node*		_expression_node;
	mm_statement* 			_statement;
	mm_statement_list* 		_statement_list;
	mm_expression_list*		_expression_list;
	mm_id_list*			_id_list;
	comparison_operator_type	_comparison_op_type;
}

%token <str> SET LET PUT GET IF ELSE LOOP USE SAVE LOAD TIME RET EXEC
%token <str> ID DECIMAL HEXADECIMAL BINARY REAL STRING
%token <str> EQ_OP LE_OP GE_OP LT_OP GT_OP NE_OP RANGE
%token <str> TRUE FALSE

%type <str> number boolean 

%type <_comparison_op_type> comparison_operator

%type <_function_call> function_call

%type <_id_list> id_list

%type <_condition> condition
%type <_argument> argument

%type <_expression_node> expression

%type <_expression_list> expression_list

%type <_st_exec> exec_statement
%type <_st_use> use_statement
%type <_st_ret> ret_statement
%type <_st_let> let_statement
%type <_st_get> get_statement
%type <_st_loop> loop_statement
%type <_st_if> if_statement
%type <_st_put> put_statement
%type <_st_set> set_statement
%type <_st_save> save_statement

%type <_statement> statement

%type <_statement_list> statement_list block main

%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%expect 11

%start main

%%

//---------------------------
// The Basic Elements
//---------------------------

number
	:	DECIMAL		{ $$ = $1; }				
	|	HEXADECIMAL	{ $$ = $1; }			
	|	BINARY		{ $$ = $1; }			
	|	REAL		{ $$ = $1; }			
	;

boolean
	:	TRUE		{ $$ = $1; }
	|	FALSE		{ $$ = $1; }
	;

function_call
	:	ID '(' ')'			{ $$ = new mm_function_call($1,NULL); }
	| 	ID '(' expression_list ')'	{ $$ = new mm_function_call($1,$3); }
	;

argument
	:	number		{ $$ = new mm_argument($1,number); }
	|	STRING		{ $$ = new mm_argument($1,alpha); }
	|	boolean		{ $$ = new mm_argument($1,boolean); }
	|	function_call	{ $$ = new mm_argument($1,function); }
	|	ID		{ $$ = new mm_argument($1,variable); }	
	;

comparison_operator
	:	EQ_OP		{ $$ = eq_operator; }
	|	LT_OP		{ $$ = lt_operator; }
	|	GT_OP		{ $$ = gt_operator; }
	|	LE_OP		{ $$ = le_operator; }
	|	GE_OP		{ $$ = ge_operator; }
	|	NE_OP		{ $$ = ne_operator; }
	;

//---------------------------
// The Building Blocks
//---------------------------

id_list
	:	ID				{ $$ = new mm_id_list(); 
						  $$->addId($1); }						
	|	id_list ',' ID			{ $1->addId($3); $$=$1; }
	;

expression
	:	argument					{ $$ = new mm_expression_node($1);  }
	|	'(' expression ')'				{ $$ = $2;  }
	|	expression '+' expression			{ $$ = new mm_expression_node(new mm_argument((char*)"+",oper),$1,$3,operator_node); }
	|	expression '-' expression			{ $$ = new mm_expression_node(new mm_argument((char*)"-",oper),$1,$3,operator_node); }
	|	expression '*' expression			{ $$ = new mm_expression_node(new mm_argument((char*)"*",oper),$1,$3,operator_node); }
	|	expression '/' expression			{ $$ = new mm_expression_node(new mm_argument((char*)"/",oper),$1,$3,operator_node); }
	|	expression '%' expression			{ $$ = new mm_expression_node(new mm_argument((char*)"%",oper),$1,$3,operator_node); }
	|	expression '^' expression			{ $$ = new mm_expression_node(new mm_argument((char*)"^",oper),$1,$3,operator_node); }
	|	'-' argument %prec UMINUS			{  }
	;

expression_list
	:	expression				{ $$ = new mm_expression_list(); 
							  $$->addExpression(new mm_expression($1)); }						
	|	expression_list ',' expression		{ $1->addExpression(new mm_expression($3)); $$=$1; }
	;

condition
	:	expression					{ $$ = new mm_condition(new mm_expression($1),empty_operator,NULL); }
	|	expression comparison_operator expression       { $$ = new mm_condition(new mm_expression($1), $2, new mm_expression($3)); }
	;

//---------------------------
// The Statements
//---------------------------

exec_statement
	:	EXEC STRING ';'				{ $$ = new mm_st_exec($2); }
	;

use_statement
	:	USE STRING ';'				{ $$ = new mm_st_use($2); /*printf("USE statement : %s\n",$2);*/ }
	;

set_statement
	:	SET ID '(' id_list ')' '=' expression ';'	{ 
									mm_st_ret* rt = new mm_st_ret(new mm_expression($7));
									mm_statement_list* stlist = new mm_statement_list();
									mm_statement* st = new mm_statement(ret_statement,rt);
									stlist->addStatement(*st);
									$$ = new mm_st_set($2,$4,stlist); 
								}
	|	SET ID '(' id_list ')' '=' block		{ $$ = new mm_st_set($2,$4,$7); }
	;

let_statement
	:	LET ID '=' expression ';'			{ $$ = new mm_st_let($2,new mm_expression($4)); }
	;

get_statement
	:	GET ID ';'					{ $$ = new mm_st_get($2); }
	;

ret_statement
	:	RET expression ';'				{ $$ = new mm_st_ret(new mm_expression($2)); }
	;

put_statement
	:	PUT expression_list ';'				{ $$ = new mm_st_put($2); }
	;

if_statement
	:	IF '(' condition ')' block			{ $$ = new mm_st_if($3,$5,NULL); }
	|	IF '(' condition ')' block ELSE block		{ $$ = new mm_st_if($3,$5,$7); }
	;

loop_statement
	:	LOOP '(' condition ')' block			{ $$ = new mm_st_loop($3,$5); }
	;

save_statement
	:	SAVE expression_list '@' STRING ';'		{ $$ = new mm_st_save($2,$4); }
	;

statement
	:	exec_statement				{ $$ = new mm_statement(exec_statement,$1); }
	|	use_statement				{ $$ = new mm_statement(use_statement,$1); }
	|	set_statement				{ $$ = new mm_statement(set_statement,$1); }
	|	let_statement				{ $$ = new mm_statement(let_statement,$1); }
	|	get_statement				{ $$ = new mm_statement(get_statement,$1); }
	|	ret_statement				{ $$ = new mm_statement(ret_statement,$1); }
	|	put_statement				{ $$ = new mm_statement(put_statement,$1); }
	|	if_statement				{ $$ = new mm_statement(if_statement,$1); }
	|	loop_statement				{ $$ = new mm_statement(loop_statement,$1); }
	|	save_statement				{ $$ = new mm_statement(save_statement,$1); }
	;

//---------------------------
// The Main Loop
//---------------------------

statement_list
	:	statement				{ $$ = new mm_statement_list(); $$->addStatement(*$1); }
	|	statement_list statement		{ $1->addStatement(*$2); $$ = $1; }
	;

block 
	:	'{' statement_list '}'			{ $$ = $2; }
	;

main
	:	statement_list				{ Base->Statements = $1; }
	;

%%

