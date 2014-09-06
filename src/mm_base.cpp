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

MM_BASE.CPP

*/

#include "mathmachine.h"

mm_base::mm_base(void) 
{
	this->Statements = new mm_statement_list();
	this->Variables = new mm_variable_list();
	this->Functions = new mm_function_list();
	this->Error = new mm_error_handling();
}

mm_base::mm_base(mm_base* b) 
{
	this->Statements = b->Statements;
	this->Variables = b->Variables;
	this->Functions = b->Functions;
	this->Error = b->Error;
}

void mm_base::mergeWith(mm_base* b)
{
	list<mm_function*>::iterator f;

	for(f=b->Functions->lst.begin(); f != b->Functions->lst.end(); ++f)
	{
		this->Functions->addFunction((*f));
	}

	list<mm_variable*>::iterator v;

	for(v=b->Variables->lst.begin(); v != b->Variables->lst.end(); ++v)
	{
		this->Variables->addVariable((*v));
	}	
}

void mm_base::execute(void)
{
	this->Statements->execute();
}

