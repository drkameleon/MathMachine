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

MM_CONSOLE.CPP

*/

#include "mathmachine.h"

mm_console::mm_console() 
{

}

void mm_console::executeCommand(string cmd)
{
	ofstream ofs (MM_CONSOLE_DEFAULT_FILE, ios::out);
	ofs << cmd;
	ofs.close();

	//cout << endl;

	Base = new mm_base();

	yyin = fopen ((char*)MM_CONSOLE_DEFAULT_FILE, "r" );	
	yyparse();

	LocalVariables = new mm_variable_list();

	Base->execute();
	cout << endl;
}

void mm_console::init()
{
	system("clear");

	while (true)
	{
		string command;
		cout << MM_CONSOLE_COMMAND_PROMPT;
		
		char Cmm[1024];

		cin.getline(Cmm,1024);
		
		if (strcmp(Cmm,"exit")!=0)
		{
			this->executeCommand(Cmm);
		}
		else
		{
			remove(MM_CONSOLE_DEFAULT_FILE);
			break;		
		}
	}	
}

