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

MM_ST_SET.CPP

*/

#include "mathmachine.h"

mm_st_set::mm_st_set(char* id, mm_id_list* args, mm_statement_list* statements)
{
	this->id = id;
	this->args = args;
	this->statements = statements;
}

mm_execution_result* mm_st_set::execute(void)
{
	// cout << "---------------------------------" << endl;
	// cout << "* New SET statement : " << endl;
	// cout << "ID = " << this->id << endl;
	// cout << "Args = " << endl;
	// this->args->showAll();
	// cout << "---------------------------------" << endl;
	Base->Functions->addFunction(new mm_function(this->id,this->args,this->statements));

	return new mm_execution_result(execution_success);
}
