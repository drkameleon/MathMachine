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

MM_FUNCTION.CPP

*/

#include "mathmachine.h"

mm_function::mm_function(char* id, mm_id_list* args, mm_statement_list* statements)
{
	this->id = id;
	this->args = args;
	this->statements = statements;	
}

mpz_class mm_function::evaluate(mm_expression_list* params)
{
	//cout << "EXECUTING A FUNCTION CALL : " << this->id << endl;
	//cout << "with params  = " << endl;
	//params->showAll(0);

	mm_variable_list* varz = new mm_variable_list();

	list<char*>::iterator i;
	mm_expression_list* prms = params;

	list<mm_expression*>::iterator x;

	x = prms->lst.begin();

	for(i=this->args->lst.begin(); i != this->args->lst.end(); ++i)
	{
		varz->addVariable(new mm_variable((*i),(*x)->evaluate().get_str()));//prms->lst.front()->evaluate().get_str()));
		x++;	
		//prms->lst.pop_front();
	}
	
	mm_variable* ret_variable = new mm_variable((char*)RETURN_VARIABLE_NAME, RETURN_VARIABLE_MAGIC_VALUE);
	varz->addVariable(ret_variable);
	
	LocalVariables = this->variables;

	//cout << endl;
	//cout << "---------------------------------" << endl;
	//cout << "Variables BEFORE execution... " << endl;
	//cout << "---------------------------------" << endl;
	//varz->showAll();
	//cout << "---------------------------------" << endl;

	list<mm_statement>::iterator j;

	for(j=this->statements->lst.begin(); j != this->statements->lst.end(); ++j)
	{
		//cout << "Setting vars..." << endl;
		(*j).setLocalVars(varz);
	}

	//cout << "Executing..." << endl;

	this->statements->execute();

	//cout << endl;
	//cout << "---------------------------------" << endl;
	//cout << "Variables AFTER execution... " << endl;
	//cout << "---------------------------------" << endl;
	//varz->showAll();
	//cout << "---------------------------------" << endl;

	return ret_variable->getValue();
}

mpz_class mm_function::evaluate(mm_expression_list* params, mm_variable_list* mvars)
{
	//cout << "EXECUTING A FUNCTION CALL : " << this->id << endl;
	//cout << "with params  = " << endl;
	//params->showAll(0);

	mm_variable_list* varz = new mm_variable_list();

	list<char*>::iterator i;
	mm_expression_list* prms = params;

	list<mm_expression*>::iterator x;

	x = prms->lst.begin();

	for(i=this->args->lst.begin(); i != this->args->lst.end(); ++i)
	{
		varz->addVariable(new mm_variable((*i),(*x)->evaluate(mvars).get_str()));//prms->lst.front()->evaluate().get_str()));
		x++;	
		//prms->lst.pop_front();
	}
	
	mm_variable* ret_variable = new mm_variable((char*)RETURN_VARIABLE_NAME, RETURN_VARIABLE_MAGIC_VALUE);
	varz->addVariable(ret_variable);
	
	LocalVariables = this->variables;

	//cout << endl;
	//cout << "---------------------------------" << endl;
	//cout << "Variables BEFORE execution... " << endl;
	//cout << "---------------------------------" << endl;
	//varz->showAll();
	//cout << "---------------------------------" << endl;

	list<mm_statement>::iterator j;

	for(j=this->statements->lst.begin(); j != this->statements->lst.end(); ++j)
	{
		//cout << "Setting vars..." << endl;
		(*j).setLocalVars(varz);
	}

	//cout << "Executing..." << endl;

	this->statements->execute();

	//cout << endl;
	//cout << "---------------------------------" << endl;
	//cout << "Variables AFTER execution... " << endl;
	//cout << "---------------------------------" << endl;
	//varz->showAll();
	//cout << "---------------------------------" << endl;

	return ret_variable->getValue();
}
mpz_class mm_function::evaluate(list<string> &params, mm_variable_list* mvars)
{
	//cout << "EXECUTING A FUNCTION CALL : " << this->id << endl;
	//cout << "with params  = " << endl;
	//params->showAll(0);

	mm_variable_list* varz = new mm_variable_list();

	list<char*>::iterator i;
	list<string> prms = params;

	list<string>::iterator x;

	x = prms.begin();

	for(i=this->args->lst.begin(); i != this->args->lst.end(); ++i)
	{
		varz->addVariable(new mm_variable((*i),(*x)));//prms->lst.front()->evaluate().get_str()));
		x++;	
		//prms->lst.pop_front();
	}
	
	mm_variable* ret_variable = new mm_variable((char*)RETURN_VARIABLE_NAME, RETURN_VARIABLE_MAGIC_VALUE);
	varz->addVariable(ret_variable);
	
	LocalVariables = this->variables;

	//cout << endl;
	//cout << "---------------------------------" << endl;
	//cout << "Variables BEFORE execution... " << endl;
	//cout << "---------------------------------" << endl;
	//varz->showAll();
	//cout << "---------------------------------" << endl;

	list<mm_statement>::iterator j;

	for(j=this->statements->lst.begin(); j != this->statements->lst.end(); ++j)
	{
		//cout << "Setting vars..." << endl;
		(*j).setLocalVars(varz);
	}

	//cout << "Executing..." << endl;

	this->statements->execute();

	//cout << endl;
	//cout << "---------------------------------" << endl;
	//cout << "Variables AFTER execution... " << endl;
	//cout << "---------------------------------" << endl;
	//varz->showAll();
	//cout << "---------------------------------" << endl;

	return ret_variable->getValue();
}



