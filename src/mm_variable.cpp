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

MM_VARIABLE.CPP

*/

#include "mathmachine.h"

mm_variable::mm_variable(char* id, string value) 
{
	this->id = id;
	this->value = value;
}

mpz_class mm_variable::getValue()
{
	mpz_class ret(this->value);

	return ret;
}


