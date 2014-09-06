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

MM_CONDITION.CPP

*/

#include "mathmachine.h"

mm_condition::mm_condition(mm_expression* left, comparison_operator_type oper, mm_expression* right) 
{
	this->left = left;
	this->oper = oper;
	this->right = right;	
}

bool mm_condition::isOK()
{
	switch (this->oper)
	{
		case eq_operator:	return (this->left->evaluate()==this->right->evaluate());
		case lt_operator:	return (this->left->evaluate()<this->right->evaluate());
		case gt_operator:	return (this->left->evaluate()>this->right->evaluate());
		case le_operator:	return (this->left->evaluate()<=this->right->evaluate());
		case ge_operator:	return (this->left->evaluate()>=this->right->evaluate());
		case ne_operator:	return (this->left->evaluate()!=this->right->evaluate());
		default:		return true;				
	}
}

bool mm_condition::isOK(mm_variable_list* myVars)
{
	switch (this->oper)
	{
		case eq_operator:	return (this->left->evaluate(myVars)==this->right->evaluate(myVars));
		case lt_operator:	return (this->left->evaluate(myVars)<this->right->evaluate(myVars));
		case gt_operator:	return (this->left->evaluate(myVars)>this->right->evaluate(myVars));
		case le_operator:	return (this->left->evaluate(myVars)<=this->right->evaluate(myVars));
		case ge_operator:	return (this->left->evaluate(myVars)>=this->right->evaluate(myVars));
		case ne_operator:	return (this->left->evaluate(myVars)!=this->right->evaluate(myVars));
		default:		return true;				
	}
}


