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

MM_ARGUMENT.CPP

*/

#include "mathmachine.h"

mm_argument::mm_argument(char* value, argument_type type)
{
	this->value = value;
	this->type = type;
}

mm_argument::mm_argument(mm_function_call* func, argument_type type)
{
	this->func = func;
	this->type = type;
}


