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

MM_VARIABLE_LIST.CPP

*/

#include "mathmachine.h"

mm_variable_list::mm_variable_list(void) 
{

}


void mm_variable_list::addVariable(mm_variable* var)
{	
	this->lst.push_back(var);	
}

mm_variable* mm_variable_list::getVariable(char* id)
{
	list<mm_variable*>::iterator i;

	for(i=this->lst.begin(); i != this->lst.end(); ++i)
	{
		if (!strcmp((*i)->id,id)) {	
					
			return (*i);
		}
	}

	return NULL;
}

bool mm_variable_list::exists(char* id)
{
	if (this->getVariable(id)==NULL) return false;
	else return true;
}

void mm_variable_list::showAll(void)
{
	list<mm_variable*>::iterator i;
	int ind = 1;

	for(i=this->lst.begin(); i != this->lst.end(); ++i)
	{
		cout << "# " << ind << " // ID = " << (*i)->id << " | Value = " << (*i)->value << endl;
		ind++;
	}
}

