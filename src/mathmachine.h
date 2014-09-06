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

MATHMACHINE.H

*/

#ifndef __MATHMACHINE_H_

//=======================================
// Includes
//=======================================

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <list>
#include <vector>
#include <stack>
#include <cstdarg>
#include <typeinfo>
#include <gmpxx.h>
#include <unistd.h>

using namespace std;

//=======================================
// Definitions
//=======================================

#define __MATHMACHINE_H_

#define MM_VERSION 	0.4
#define MM_SUBVERSION	0

#define MM_AUTHOR	"Dr.Kameleon"
#define MM_AUTHOR_EMAIL "drkameleon@gmail.com"

#define RETURN_VARIABLE_NAME "RET"
#define RETURN_VARIABLE_MAGIC_VALUE "18966"

#define ERROR_VARIABLE_NOT_FOUND 	"The variable was not defined"
#define ERROR_FAILURE_DURING_EXECUTION 	"Failure during command execution"
#define ERROR_FILE_NOT_FOUND	 	"File not found"

#define MM_CONSOLE_DEFAULT_FILE 	"runtime.mm"
#define MM_CONSOLE_COMMAND_PROMPT	"MathMachine >> "

//=======================================
// Declarations
//=======================================

// EXTERNAL
//---------------------

extern FILE *yyin;
extern char *yytext; 
extern int yylex(void);
extern int yyparse(void);
extern int yycolumn;

// Forward declarations
//-----------------------------

enum statement_type 
{ 
	exec_statement,
	use_statement,
	set_statement,
	let_statement,
	get_statement,
	ret_statement,
	put_statement,
	if_statement,
	loop_statement,
	save_statement,
	no_statement
};

enum comparison_operator_type 
{ 
	eq_operator,
	lt_operator,
	gt_operator,
	le_operator,
	ge_operator,
	ne_operator,
	empty_operator
};

enum argument_type
{
	number,
	alpha,
	variable,
	boolean,
	function,
	oper
};

enum expression_node_type
{
	operator_node,
	operand_node
};

enum execution_result_type
{
	execution_success,
	execution_break,
	execution_failure
};

class mm_id_list;
class mm_statement_list;
class mm_expression_list;
class mm_variable_list;
class mm_execution_result;

// mm_utils.cpp
//---------------------

void trimString(string& str,char ch);
vector<string> split(const char *str, char c);
string getFolderFromPath(char* path);
bool fileExists(string filename);

// mm_math_library.cpp
//---------------------

mpz_class getPower(mpz_class a, mpz_class b);

// mm_function_call.cpp
//---------------------

class mm_function_call
{
	public:
		char* id;
		mm_expression_list* params;

		mm_function_call(char* id, mm_expression_list* params);
};

// mm_argument.cpp
//---------------------

class mm_argument
{
	public:
		argument_type type;
		char* value;
		mm_function_call* func;

		mm_argument(char* value, argument_type type);
		mm_argument(mm_function_call* func, argument_type type);
};

// mm_expression_node.cpp
//---------------------

class mm_expression_node
{
	public:
		mm_expression_node* left;
		mm_expression_node* right;
		expression_node_type type;
		mm_argument* argument;

		mm_expression_node(mm_argument* argument);		
		mm_expression_node(mm_argument* argument, mm_expression_node* left, mm_expression_node* right, expression_node_type type);
};

// mm_expression.cpp
//---------------------

class mm_expression
{
	public:
		mm_expression_node* expression;

		mm_expression(mm_expression_node* expression);
		void showNode(mm_expression_node* nd, int level);
		void show();

		mpz_class evaluateNode(mm_expression_node* nd);
		mpz_class evaluateNode(mm_expression_node* nd, mm_variable_list* myVars);
		
		mpz_class evaluate();
		mpz_class evaluate(mm_variable_list* myVars);

		void echo();
		void echo(mm_variable_list* myVars);

		void echoToFile(ofstream &file_handle);
		void echoToFile(ofstream &file_handle, mm_variable_list* myVars);
};


// mm_condition.cpp
//---------------------

class mm_condition
{
	public:
		mm_expression* left;
		comparison_operator_type oper;
		mm_expression* right;

		mm_condition(mm_expression* left, comparison_operator_type oper, mm_expression* right);

		bool isOK();
		bool isOK(mm_variable_list* myVars);
};

// mm_st_exec.cpp
//---------------------

class mm_st_exec
{
	public:
		char* command;
		mm_variable_list* myVariables;

		mm_st_exec(char* command); 

		mm_execution_result* execute(void);
};

// mm_st_use.cpp
//---------------------

class mm_st_use
{
	public:
		char* id;
		mm_variable_list* myVariables;

		mm_st_use(char* id); 

		mm_execution_result* execute(void);
};

// mm_st_ret.cpp
//---------------------

class mm_st_ret
{
	public:
		mm_expression* expression;
		mm_variable_list* myVariables;

		mm_st_ret(mm_expression* expression); 

		mm_execution_result* execute(void);
};

// mm_st_loop.cpp
//---------------------

class mm_st_loop
{
	public:
		mm_condition* condition;
		mm_statement_list* statements;
		mm_variable_list* myVariables;

		mm_st_loop(mm_condition* condition, mm_statement_list* statements); 

		mm_execution_result* execute(void);
};

// mm_st_if.cpp
//---------------------

class mm_st_if
{
	public:
		mm_condition* condition;
		mm_statement_list* statements;
		mm_statement_list* else_statements;
		mm_variable_list* myVariables;

		mm_st_if(mm_condition* condition, mm_statement_list* statements, mm_statement_list* else_statements); 

		mm_execution_result* execute(void);
};

// mm_st_set.cpp
//---------------------

class mm_st_set
{
	public:
		char* id;
		mm_id_list* args;
		mm_statement_list* statements;
		mm_variable_list* myVariables;

		mm_st_set(char* id, mm_id_list* args, mm_statement_list* statements); 

		mm_execution_result* execute(void);
};

// mm_st_let.cpp
//---------------------

class mm_st_let
{
	public:
		char* id;
		mm_expression* expression;
		mm_variable_list* myVariables;

		mm_st_let(char* id, mm_expression* expression); 

		mm_execution_result* execute(void);
};

// mm_st_get.cpp
//---------------------

class mm_st_get
{
	public:
		char* id;
		mm_variable_list* myVariables;
		
		mm_st_get(char* id); 

		mm_execution_result* execute(void);
};

// mm_st_put.cpp
//---------------------

class mm_st_put
{
	public:
		mm_expression_list* expressions;
		mm_variable_list* myVariables;

		mm_st_put(mm_expression_list* expressions); 

		mm_execution_result* execute(void);
};

// mm_st_save.cpp
//---------------------

class mm_st_save
{
	public:
		mm_expression_list* expressions;
		string filename;
		mm_variable_list* myVariables;

		mm_st_save(mm_expression_list* expressions,char* filename); 

		mm_execution_result* execute(void);
};

// mm_expression_list.cpp
//--------------------------

class mm_expression_list
{
	public:
		list<mm_expression*> lst;

		mm_expression_list(void);
		void addExpression(mm_expression* expr);
		void showAll(int level);
};

// mm_id_list.cpp
//--------------------------

class mm_id_list
{
	public:
		list<char*> lst;

		mm_id_list(void);
		void addId(char* id);

		void showAll();
};

// mm_execution_result.cpp
//--------------------------

class mm_execution_result
{
	public:
		enum execution_result_type result;
		union {
			char* str;
			int num;
		} value;

		mm_execution_result(execution_result_type result);
};

// mm_function.cpp
//--------------------------

class mm_function
{
	public:
		char* id;
		mm_id_list* args;
		mm_statement_list* statements;
		mm_variable_list* variables;

		mm_function(char* id, mm_id_list* args, mm_statement_list* statements); 

		mpz_class evaluate(mm_expression_list* params);
		mpz_class evaluate(mm_expression_list* params, mm_variable_list* mvars);
		mpz_class evaluate(list<string> &params, mm_variable_list* mvars);
};

// mm_function_list.cpp
//--------------------------

class mm_function_list
{
	public:
		list<mm_function*> lst;

		mm_function_list(void);
		void addFunction(mm_function* func);

		mm_function* getFunction(char* id);
		bool exists(char* id);

		void showAll(void);
};

// mm_variable.cpp
//--------------------------

class mm_variable
{
	public:
		char* id;
		string value;

		mm_variable(char* id, string value);

		mpz_class getValue();
};

// mm_variable_list.cpp
//--------------------------

class mm_variable_list
{
	public:
		list<mm_variable*> lst;

		mm_variable_list(void);
		void addVariable(mm_variable* var);

		mm_variable* getVariable(char* id);
		bool exists(char* id);

		void showAll(void);
};

// mm_statement.cpp
//---------------------

class mm_statement
{
	public:
		enum statement_type type;

		union {
			mm_st_exec* exec;
			mm_st_use* use;
			mm_st_ret* ret;
			mm_st_set* set;
			mm_st_let* let;
			mm_st_get* get;
			mm_st_loop* loop;
			mm_st_if* ifs;
			mm_st_put* put;
			mm_st_save* save;
		} body;

		mm_variable_list* myVariables;

		mm_statement(statement_type tp); 
		mm_statement(statement_type tp, mm_st_exec* execst);
		mm_statement(statement_type tp, mm_st_use* usest);
		mm_statement(statement_type tp, mm_st_ret* retst);
		mm_statement(statement_type tp, mm_st_set* setst);
		mm_statement(statement_type tp, mm_st_let* letst);
		mm_statement(statement_type tp, mm_st_get* getst);
		mm_statement(statement_type tp, mm_st_loop* loopst);
		mm_statement(statement_type tp, mm_st_if* ifst);
		mm_statement(statement_type tp, mm_st_put* putst);
		mm_statement(statement_type tp, mm_st_save* savest);

		void setLocalVars(mm_variable_list* mvars);

		mm_execution_result* execute(void);
};

// mm_statement_list.cpp
//---------------------

class mm_statement_list
{
	public:
		list<mm_statement> lst;

		mm_statement_list(void);
		void addStatement(mm_statement st);
		void showAll(int level);

		void execute(void);
};

// mm_error_handling.cpp
//---------------------

class mm_error_handling
{
	public:
		mm_error_handling(void);

		void halt(string msg);
};

// mm_base.cpp
//---------------------

class mm_base
{
	public:
		mm_statement_list* Statements;
		mm_variable_list* Variables;
		mm_function_list* Functions;

		mm_error_handling* Error;

		mm_base(void);
		mm_base(mm_base* b);

		void mergeWith(mm_base* b);

		void execute(void);
};

// mm_console.cpp
//---------------------

class mm_console
{
	public:
		mm_console(void);
		void init(void);
		void executeCommand(string cmd);
};


//=======================================
// 'Coz they gotta be... extrovert !
//=======================================

extern mm_variable_list* LocalVariables;
extern mm_base* Base;
extern mm_console* Console;
extern string BasePath;


#endif

