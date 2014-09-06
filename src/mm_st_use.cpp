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

MM_ST_USE.CPP

*/

#include "mathmachine.h"

mm_st_use::mm_st_use(char* id)
{
	this->id = id;
}

mm_execution_result* mm_st_use::execute(void)
{
	mm_base* oldBase = new mm_base(Base);
	Base = new mm_base();

	string s = (string) this->id;
	trimString(s,'"');

	string Path = BasePath + "/" + s;

	if (!fileExists(Path))
		Base->Error->halt(ERROR_FILE_NOT_FOUND);

	yyin = fopen ( Path.c_str() , "r" );	
	yyparse();

	Base->execute();

	oldBase->mergeWith(Base);

	Base = oldBase;

	return new mm_execution_result(execution_success);
}
