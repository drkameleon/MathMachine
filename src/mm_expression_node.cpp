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

MM_EXPRESSION_NODE.CPP

*/

#include "mathmachine.h"

mm_expression_node::mm_expression_node(mm_argument* argument) 
{
	this->argument = argument;
	this->left = NULL;
	this->right = NULL;
	this->type = operand_node;
}

mm_expression_node::mm_expression_node(mm_argument* argument, mm_expression_node* left, mm_expression_node* right, expression_node_type type) 
{
	this->argument = argument;
	this->left = left;
	this->right = right;
	this->type = type;
}

