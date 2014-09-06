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

MM_ST_LOOP.CPP

*/

#include "mathmachine.h"

mm_st_loop::mm_st_loop(mm_condition* condition, mm_statement_list* statements)
{
	this->condition = condition;
	this->statements = statements;
}

mm_execution_result* mm_st_loop::execute(void)
{
	while (this->condition->isOK(this->myVariables))
	{
		list<mm_statement>::iterator j;

		for(j=this->statements->lst.begin(); j != this->statements->lst.end(); ++j)
		{
			(*j).setLocalVars(this->myVariables);
		}

		// cout << "Executing the IFs" << endl;
		this->statements->execute();
	}
	return new mm_execution_result(execution_success);
}
