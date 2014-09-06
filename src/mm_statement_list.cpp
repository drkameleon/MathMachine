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

MM_STATEMENT_LIST.CPP

*/

#include "mathmachine.h"

mm_statement_list::mm_statement_list(void) 
{

}


void mm_statement_list::addStatement(mm_statement st)
{
	this->lst.push_back(st);
}

void mm_statement_list::execute(void)
{
	list<mm_statement>::iterator i;

	for(i=this->lst.begin(); i != this->lst.end(); ++i)
	{
		mm_execution_result* exec = (*i).execute();

		if (exec->result==execution_success) { /* SUCCESS */ }
		else if (exec->result==execution_break) { break; }
		else if (exec->result==execution_failure)
		{
			Base->Error->halt(ERROR_FAILURE_DURING_EXECUTION);	
		}
	}
}

void mm_statement_list::showAll(int level)
{
	string pre = "";
	for (int j=0; j<level; j++)
		pre += "\t\t\t";

	list<mm_statement>::iterator i;

	for(i=this->lst.begin(); i != this->lst.end(); ++i)
	{
		if ((*i).type==use_statement)	
		{
			cout << pre << "USE :\n";
			cout << pre << "\tid = " << (*i).body.use->id << endl;
		}
		else if ((*i).type==set_statement)
		{
			cout << pre << "SET :\n";
			
		}
		else if ((*i).type==let_statement)
		{
			cout << pre << "LET :\n";
			cout << pre << "\tid = " << (*i).body.let->id << endl;
			cout << pre << "\texpression = " << (*i).body.let->expression << endl;
		}
		else if ((*i).type==ret_statement)
		{
			cout << pre << "RET :\n";
			cout << pre << "\texpression = " << (*i).body.ret->expression << endl;
		}
		else if ((*i).type==put_statement)
		{
			cout << pre << "PUT :\n";
			cout << pre << "\texpressions = " << endl;
			(*i).body.put->expressions->showAll(level+1);
		}
		else if ((*i).type==if_statement)
		{
			cout << pre << "IF :\n";
			cout << pre << "\tcondition = " << (*i).body.ifs->condition << endl;
			cout << pre << "\tstatements = " << endl;
			(*i).body.ifs->statements->showAll(level+1);
		}
		else if ((*i).type==loop_statement)
		{
			cout << pre << "LOOP :\n";
			cout << pre << "\tcondition = " << (*i).body.loop->condition << endl;
			cout << pre << "\tstatements = " << endl;
			(*i).body.loop->statements->showAll(level+1);
		}
	}
}
