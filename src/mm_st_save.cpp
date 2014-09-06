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

MM_ST_SAVE.CPP

*/

#include "mathmachine.h"

mm_st_save::mm_st_save(mm_expression_list* expressions, char* filename)
{
	string fname = (string) filename;
	trimString(fname, '"');

	this->expressions = expressions;
	this->filename = fname;
}

mm_execution_result* mm_st_save::execute(void)
{
	list<mm_expression*>::iterator i;

	ofstream file_handle(this->filename.c_str(),ios::app);

	for(i=this->expressions->lst.begin(); i != this->expressions->lst.end(); ++i)
	{
		if (this->myVariables!=NULL)
			(*i)->echoToFile(file_handle, this->myVariables);
		else	
			(*i)->echoToFile(file_handle);
	}
	file_handle << endl;
	file_handle.close();

	return new mm_execution_result(execution_success);
}
