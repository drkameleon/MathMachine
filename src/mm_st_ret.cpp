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

MM_ST_RET.CPP

*/

#include "mathmachine.h"

mm_st_ret::mm_st_ret(mm_expression* expression)
{
	this->expression = expression;
}

mm_execution_result* mm_st_ret::execute(void)
{
	mm_variable* var = this->myVariables->getVariable((char*)RETURN_VARIABLE_NAME);

	var->value = this->expression->evaluate(this->myVariables).get_str();

	return new mm_execution_result(execution_break);
}
