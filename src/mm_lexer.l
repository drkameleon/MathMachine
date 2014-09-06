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

MM_LEXER.L

*/

#include "mathmachine.h"

#include <stdio.h>
#include "y.tab.h"

void count();
%}

DIGIT			[0-9]
LETTER			[a-zA-Z_]
HEX			[a-fA-F0-9]
BINARY			[0-1]

%%
^[ \t]*"//".*\n				{ /* This is a '//' single-line comment */ }
^[ \t]*"#!".*\n				{ /* This is a '#!' single-line comment */ }
"use"					{ count(); return(USE); }
"set"					{ count(); return(SET); }
"let"					{ count(); return(LET); }
"ret"					{ count(); return(RET); }
"put"					{ count(); return(PUT); }
"get"					{ count(); return(GET); }
"if"					{ count(); return(IF); }
"else"					{ count(); return(ELSE); }
"loop"					{ count(); return(LOOP); }
"save"					{ count(); return(SAVE); }
"exec"					{ count(); return(EXEC); }


"true"					{ count(); return(TRUE); }
"false"					{ count(); return(FALSE); }

{LETTER}({LETTER}|{DIGIT})*		{ count(); return(ID); }

{DIGIT}+				{ count(); return(DECIMAL); 	/* DECIMAL NUMBER */}
0"h"{HEX}+				{ count(); return(HEXADECIMAL); /* HEXADECIMAL NUMBER */}
0"b"{BINARY}+				{ count(); return(BINARY); 	/* BINARY NUMBER */}  
{DIGIT}+"."{DIGIT}+			{ count(); return(REAL); 	/* REAL NUMBER */}

\"(\\.|[^\\"])*\"			{ count(); return(STRING); }

"=="					{ count(); return(EQ_OP); }
"<="					{ count(); return(LE_OP); }
">="					{ count(); return(GE_OP); }
"<"					{ count(); return(LT_OP); }
">"					{ count(); return(GT_OP); }
"!="					{ count(); return(NE_OP); }

"-->"					{ count(); return(RANGE); }

"("					{ count(); return('('); }
")"					{ count(); return(')'); }
"{"					{ count(); return('{'); }
"}"					{ count(); return('}'); }
"["					{ count(); return('['); }
"]"					{ count(); return(']'); }

"-"					{ count(); return('-'); }
"+"					{ count(); return('+'); }
"*"					{ count(); return('*'); }
"/"					{ count(); return('/'); }

"="					{ count(); return('='); }
";"					{ count(); return(';'); }
","					{ count(); return(','); }
":"					{ count(); return(':'); }
"."					{ count(); return('.'); }
"?"					{ count(); return('?'); }
"%"					{ count(); return('%'); }
"&"					{ count(); return('&'); }
"$"					{ count(); return('$'); }
"#"					{ count(); return('#'); }
"@"					{ count(); return('@'); }
"|"					{ count(); return('|'); }
"!"					{ count(); return('!'); }
"~"					{ count(); return('~'); }
"^"					{ count(); return('^'); }

[ \t\v\n\f]				{ count(); }
.					{ /* ignore it */ } 

	

%%

int yycolumn = 0;

void count()
{
	int i;
	
	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			yycolumn = 0;
		else if (yytext[i] == '\t')
			yycolumn += 8 - (yycolumn % 8);
		else
			yycolumn++;

	// ECHO;
	yylval.str=strdup(yytext);
}



