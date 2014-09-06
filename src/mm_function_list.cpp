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

MM_FUNCTION_LIST.CPP

*/

#include "mathmachine.h"

mm_function_list::mm_function_list(void) 
{

}


void mm_function_list::addFunction(mm_function* func)
{	
	this->lst.push_back(func);	
}

mm_function* mm_function_list::getFunction(char* id)
{
	list<mm_function*>::iterator i;

	for(i=this->lst.begin(); i != this->lst.end(); ++i)
	{
		if (!strcmp((*i)->id,id)) {	
					
			return (*i);
		}
	}

	return NULL;
}

bool mm_function_list::exists(char* id)
{
	if (this->getFunction(id)==NULL) return false;
	else return true;
}

void mm_function_list::showAll(void)
{
	list<mm_function*>::iterator i;
	int ind = 1;

	for(i=this->lst.begin(); i != this->lst.end(); ++i)
	{
		cout << "# " << ind << " // ID = " << (*i)->id << endl;
		ind++;
	}
}

