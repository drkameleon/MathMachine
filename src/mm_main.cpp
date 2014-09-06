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

MM_MAIN.CPP

*/

#include "mathmachine.h"

mm_console* Console;
mm_base* Base;
string BasePath;
mm_variable_list* LocalVariables;

//===========================================
// The illusion of a minimalistic Core
//===========================================

int main(int argc, char **argv)
{
	#ifdef MM_CONSOLE_VERSION
		Console = new mm_console();
		Console->init();	
	#else
		Base = new mm_base();
	
		char *path=NULL;
		size_t size = 0;
		path = getcwd(path,size);

		BasePath = (string) path + "/" + getFolderFromPath(argv[1]);
		// cout << "BasePath = " << BasePath << endl;

		if (!fileExists((string)argv[1]))
			Base->Error->halt(ERROR_FILE_NOT_FOUND);	

		yyin = fopen ( argv[1], "r" );	
		yyparse();

		LocalVariables = new mm_variable_list();

		Base->execute();

	#endif

	return 0;
}

