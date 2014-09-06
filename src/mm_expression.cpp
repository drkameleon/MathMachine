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

MM_EXPRESSION.CPP

*/

#include "mathmachine.h"

mm_expression::mm_expression(mm_expression_node* expression) 
{
	this->expression = expression;
}

void mm_expression::showNode(mm_expression_node* nd, int level)
{
	string pre = "";
	for (int j=0; j<level; j++)
		pre += "\t\t\t";

	if (nd!=NULL)
	{
		cout << pre << nd->argument->value << endl;

		this->showNode(nd->left,level+1);
		this->showNode(nd->right,level+1);
		
	}
}

void mm_expression::show()
{
	this->showNode(this->expression,0);
}

mpz_class mm_expression::evaluateNode(mm_expression_node* nd)
{
	//cout << "*** IN EVALUATE : withOUT local vars" << endl;
	if (nd!=NULL)
	{
		if (nd->type == operator_node)
		{
			if (!strcmp(nd->argument->value,"+"))
				return evaluateNode(nd->left) + evaluateNode(nd->right);
			else if (!strcmp(nd->argument->value,"-"))
				return evaluateNode(nd->left) - evaluateNode(nd->right);
			else if (!strcmp(nd->argument->value,"*"))
				return evaluateNode(nd->left) * evaluateNode(nd->right);
			else if (!strcmp(nd->argument->value,"/"))
				return evaluateNode(nd->left) / evaluateNode(nd->right);
			else if (!strcmp(nd->argument->value,"%"))
				return evaluateNode(nd->left) % evaluateNode(nd->right);
			else if (!strcmp(nd->argument->value,"^"))
				return getPower(evaluateNode(nd->left),evaluateNode(nd->right));
		}
		else
		{
			if (nd->argument->type==number)
			{
				mpz_class a(nd->argument->value);

				return a;
			}
			else if (nd->argument->type==variable)
			{
				mm_variable* var;

				if (Base->Variables->exists(nd->argument->value))
				{
					var = Base->Variables->getVariable(nd->argument->value);
				}
				else if (LocalVariables->exists(nd->argument->value))
				{
					var = LocalVariables->getVariable(nd->argument->value);
				}
				else
				{
					Base->Error->halt(ERROR_VARIABLE_NOT_FOUND);
				}

				mpz_class a(var->value);
				return a;
			}
			else if (nd->argument->type==function)
			{
				mm_function* func = Base->Functions->getFunction(nd->argument->func->id);

				return func->evaluate(nd->argument->func->params);
			}
		}
	}

	mpz_class nothing = 0;
	return nothing;
}

mpz_class mm_expression::evaluateNode(mm_expression_node* nd, mm_variable_list* myVars)
{
	//cout << "*** IN EVALUATE : WITH local vars" << endl;
	if (nd!=NULL)
	{
		if (nd->type == operator_node)
		{
			if (!strcmp(nd->argument->value,"+"))
				return evaluateNode(nd->left,myVars) + evaluateNode(nd->right,myVars);
			else if (!strcmp(nd->argument->value,"-"))
				return evaluateNode(nd->left,myVars) - evaluateNode(nd->right,myVars);
			else if (!strcmp(nd->argument->value,"*"))
				return evaluateNode(nd->left,myVars) * evaluateNode(nd->right,myVars);
			else if (!strcmp(nd->argument->value,"/"))
				return evaluateNode(nd->left,myVars) / evaluateNode(nd->right,myVars);
			else if (!strcmp(nd->argument->value,"%"))
				return evaluateNode(nd->left,myVars) % evaluateNode(nd->right,myVars);
			else if (!strcmp(nd->argument->value,"^"))
				return getPower(evaluateNode(nd->left,myVars),evaluateNode(nd->right,myVars));
		}
		else
		{
			if (nd->argument->type==number)
			{
				mpz_class a(nd->argument->value);

				return a;
			}
			else if (nd->argument->type==variable)
			{
				mm_variable* var;

				if (Base->Variables->exists(nd->argument->value))
				{
					var = Base->Variables->getVariable(nd->argument->value);
				}
				else if (myVars->exists(nd->argument->value))
				{
					var = myVars->getVariable(nd->argument->value);
				}
				else
				{
					Base->Error->halt(ERROR_VARIABLE_NOT_FOUND);
				}

				mpz_class a(var->value);
				return a;
			}
			else if (nd->argument->type==function)
			{
				mm_function* func = Base->Functions->getFunction(nd->argument->func->id);
		
				list<string> paramList;

				list<mm_expression*>::iterator x;


				for(x=nd->argument->func->params->lst.begin(); x != nd->argument->func->params->lst.end(); ++x)
				{
					paramList.push_back((*x)->evaluate(myVars).get_str());
				}
				
				// cout << "CALLING FUNC WITH+++ Params " << endl;
				return func->evaluate(paramList,myVars);
			}
		}
	}

	mpz_class nothing = 0;
	return nothing;
}

mpz_class mm_expression::evaluate(mm_variable_list* myVars)
{		
	mpz_class ret = this->evaluateNode(this->expression, myVars);

	return ret;
}

mpz_class mm_expression::evaluate()
{		
	mpz_class ret = this->evaluateNode(this->expression);

	return ret;
}

void mm_expression::echo()
{
	if (this->expression->argument->type==alpha) {
		string s = (string)this->expression->argument->value;
		trimString(s,'"');
		cout << s;
	}
	else 
	{
		cout << this->evaluateNode(this->expression);
	}
}

void mm_expression::echo(mm_variable_list* myVars)
{
	if (this->expression->argument->type==alpha) {
		string s = (string)this->expression->argument->value;
		trimString(s,'"');
		cout << s;
	}
	else 
	{
		cout << this->evaluateNode(this->expression,myVars);
	}
}

void mm_expression::echoToFile(ofstream &file_handle)
{
	if (this->expression->argument->type==alpha) {
		string s = (string)this->expression->argument->value;
		trimString(s,'"');
		file_handle << s;
	}
	else 
	{
		file_handle << this->evaluateNode(this->expression);
	}
}

void mm_expression::echoToFile(ofstream &file_handle, mm_variable_list* myVars)
{
	if (this->expression->argument->type==alpha) {
		string s = (string)this->expression->argument->value;
		trimString(s,'"');
		file_handle << s;
	}
	else 
	{
		file_handle << this->evaluateNode(this->expression, myVars);
	}
}

