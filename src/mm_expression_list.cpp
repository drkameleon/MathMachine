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

MM_EXPRESSION_LIST.CPP

*/

#include "mathmachine.h"

mm_expression_list::mm_expression_list(void) 
{

}


void mm_expression_list::addExpression(mm_expression* expr)
{
	this->lst.push_back(expr);
}

void mm_expression_list::showAll(int level)
{
	string pre = "";
	for (int j=0; j<level; j++)
		pre += "\t\t\t";

	list<mm_expression*>::iterator i;

	for(i=this->lst.begin(); i != this->lst.end(); ++i)
	{	
		//cout << "another one" << endl;
		(*i)->show();
		(*i)->evaluate();
		//cout << pre << "\t" << (*i)->show() << endl;
	}
}


