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

MM_ID_LIST.CPP

*/

#include "mathmachine.h"

mm_id_list::mm_id_list(void) 
{

}


void mm_id_list::addId(char* id)
{
	this->lst.push_back(id);
}

void mm_id_list::showAll()
{
	list<char*>::iterator i;

	for(i=this->lst.begin(); i != this->lst.end(); ++i)
	{	
		cout << (*i) << endl;
	}
}


