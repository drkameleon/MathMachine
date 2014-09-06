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

MM_STATEMENT.CPP

*/

#include "mathmachine.h"

mm_statement::mm_statement(statement_type tp) 
{
	this->type = tp;
	this->myVariables = NULL;
}

mm_statement::mm_statement(statement_type tp, mm_st_exec* execst) 
{
	this->type = tp;
	this->body.exec = execst;
	this->myVariables = NULL;
}

mm_statement::mm_statement(statement_type tp, mm_st_use* usest) 
{
	this->type = tp;
	this->body.use = usest;
	this->myVariables = NULL;
}

mm_statement::mm_statement(statement_type tp, mm_st_ret* retst) 
{
	this->type = tp;
	this->body.ret = retst;
	this->myVariables = NULL;
}

mm_statement::mm_statement(statement_type tp, mm_st_set* setst) 
{
	this->type = tp;
	this->body.set = setst;
	this->myVariables = NULL;
}

mm_statement::mm_statement(statement_type tp, mm_st_let* letst) 
{
	this->type = tp;
	this->body.let = letst;
	this->myVariables = NULL;
}

mm_statement::mm_statement(statement_type tp, mm_st_get* getst) 
{
	this->type = tp;
	this->body.get = getst;
	this->myVariables = NULL;
}

mm_statement::mm_statement(statement_type tp, mm_st_loop* loopst) 
{
	this->type = tp;
	this->body.loop = loopst;
	this->myVariables = NULL;
}

mm_statement::mm_statement(statement_type tp, mm_st_if* ifst) 
{
	this->type = tp;
	this->body.ifs = ifst;
	this->myVariables = NULL;
}

mm_statement::mm_statement(statement_type tp, mm_st_put* putst) 
{
	this->type = tp;
	this->body.put = putst;
	this->myVariables = NULL;
}

mm_statement::mm_statement(statement_type tp, mm_st_save* savest) 
{
	this->type = tp;
	this->body.save = savest;
	this->myVariables = NULL;
}

mm_execution_result* mm_statement::execute(void)
{
	if (this->type==put_statement)
		return this->body.put->execute();
	else if (this->type==use_statement)
		return this->body.use->execute();
	else if (this->type==exec_statement)
		return this->body.exec->execute();
	else if (this->type==if_statement)
		return this->body.ifs->execute();
	else if (this->type==loop_statement)
		return this->body.loop->execute();
	else if (this->type==let_statement)
		return this->body.let->execute();
	else if (this->type==get_statement)
		return this->body.get->execute();
	else if (this->type==set_statement)
		return this->body.set->execute();
	else if (this->type==ret_statement)
		return this->body.ret->execute();
	else if (this->type==save_statement)
		return this->body.save->execute();
	else
		return new mm_execution_result(execution_failure);

}

void mm_statement::setLocalVars(mm_variable_list* mvars)
{ 
	if (this->type==put_statement)
		this->body.put->myVariables = mvars;
	else if (this->type==exec_statement)
		this->body.exec->myVariables = mvars;
	else if (this->type==if_statement)
		this->body.ifs->myVariables = mvars;
	else if (this->type==loop_statement)
		this->body.loop->myVariables = mvars;
	else if (this->type==let_statement)
		this->body.let->myVariables = mvars;
	else if (this->type==get_statement)
		this->body.get->myVariables = mvars;
	else if (this->type==set_statement)
		this->body.set->myVariables = mvars;
	else if (this->type==ret_statement)
		this->body.ret->myVariables = mvars;
	else if (this->type==save_statement)
		this->body.save->myVariables = mvars;

	this->myVariables = mvars; 
}

