#
# MathMachine
# Copyright (C) 2009-2011 Dr.Kameleon
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>
# 
# ---------------------------
# MAKEFILE
# ---------------------------
# 

#-------------------------
# Definitions
#-------------------------

# Paths
SRC  = src
BIN  = bin
LIB  = lib
EXA  = examples
TOO  = tools
DEST = /usr/bin

APP_CONSOLE  = mathmachine
APP_COMPILER = mmc

# Tools & commands
CPP  = g++
CC   = cc

LEX  = lex
YACC = yacc

RM   = rm -f
MV   = mv
CP   = cp

SHOW = ${TOO}/show.sh
CLOC = ${TOO}/cloc-1.51.pl

CLOC_FLAGS = --exclude-dir=${TOO},${EXA}

# C++ stuff

CPP_OBJECTS	= mm_main.o\
		  mm_base.o\
		  mm_console.o\
		  mm_variable.o\
		  mm_variable_list.o\
		  mm_function.o\
		  mm_function_list.o\
		  mm_function_call.o\
		  mm_id_list.o\
		  mm_statement.o\
		  mm_statement_list.o\
		  mm_argument.o\
		  mm_expression.o\
		  mm_expression_node.o\
		  mm_expression_list.o\
		  mm_execution_result.o\
		  mm_condition.o\
		  mm_st_exec.o\
		  mm_st_use.o\
		  mm_st_ret.o\
		  mm_st_set.o\
		  mm_st_let.o\
		  mm_st_get.o\
		  mm_st_loop.o\
		  mm_st_if.o\
		  mm_st_put.o\
		  mm_st_save.o\
		  mm_error_handling.o\
		  mm_math_library.o\
		  mm_utils.o


CPP_SOURCES 	= ${SRC}/mm_main.cpp\
	          ${SRC}/mm_base.cpp\
		  ${SRC}/mm_console.cpp\
		  ${SRC}/mm_variable.cpp\
		  ${SRC}/mm_variable_list.cpp\
		  ${SRC}/mm_function.cpp\
		  ${SRC}/mm_function_list.cpp\
		  ${SRC}/mm_function_call.cpp\
		  ${SRC}/mm_id_list.cpp\
		  ${SRC}/mm_statement.cpp\
		  ${SRC}/mm_statement_list.cpp\
		  ${SRC}/mm_argument.cpp\
		  ${SRC}/mm_expression.cpp\
		  ${SRC}/mm_expression_node.cpp\
		  ${SRC}/mm_expression_list.cpp\
		  ${SRC}/mm_execution_result.cpp\
		  ${SRC}/mm_condition.cpp\
		  ${SRC}/mm_st_exec.cpp\
		  ${SRC}/mm_st_use.cpp\
		  ${SRC}/mm_st_ret.cpp\
		  ${SRC}/mm_st_set.cpp\
		  ${SRC}/mm_st_let.cpp\
		  ${SRC}/mm_st_get.cpp\
		  ${SRC}/mm_st_loop.cpp\
		  ${SRC}/mm_st_if.cpp\
		  ${SRC}/mm_st_put.cpp\
		  ${SRC}/mm_st_save.cpp\
		  ${SRC}/mm_error_handling.cpp\
		  ${SRC}/mm_math_library.cpp\
		  ${SRC}/mm_utils.cpp

CPP_CONSOLE_FLAG = -DMM_CONSOLE_VERSION
CPP_FLAGS 	= -Wall -Wno-write-strings -fexceptions 
CPP_LIBS  	= -ll -lgmpxx -lgmp

CPP_HEADER 	= mathmachine.h

# C stuff
CC_OBJECTS  	= lex.yy.o y.tab.o
CC_SOURCES  	= lex.yy.c y.tab.c
CC_FLAGS  	= -c -x c++
CC_LEXER   	= ${SRC}/mm_lexer.l
CC_PARSER  	= ${SRC}/mm_parser.y

#-----------------------------------------------------------
# What are we 'making'? The Compiler OR the Console?
#-----------------------------------------------------------

ifeq (${TARGET}, console)
	APP = ${APP_CONSOLE}
	MESSAGE = "*  Preparing the MathMachine Console (mathmachine)"
	CPP_CONSOLE_FLAGS = -DMM_CONSOLE_VERSION
else
	APP = ${APP_COMPILER}
	MESSAGE = "*  Preparing the MathMachine Compiler (mmc)"
	CPP_CONSOLE_FLAGS =
endif

#-------------------------
# Main Functions
#-------------------------

all: ${APP} install clean
	@echo "----------------------------------------"
	@echo "* DONE! :-)"
	@echo "----------------------------------------"

${APP}: ${CPP_OBJECTS} ${CC_OBJECTS}
	@echo "----------------------------------------"
	@echo "* Linking..."
	@echo "----------------------------------------"
	${CPP} ${CFLAGS} ${CPP_OBJECTS} ${CC_OBJECTS} -o ${APP} ${CPP_LIBS}
	${MV} ${APP} ${BIN}

${CPP_OBJECTS}: ${CPP_SOURCES}
	@echo "========================================================"
	@echo "* MathMachine"
	@echo "* Version 0.4.0"
	@echo "*"
	@echo "* Copyright (c) 2009-2011"
	@echo "* By Dr.Kameleon"
	@echo "========================================================"
	@echo ""
	@echo "********************************************************"
	@echo ${MESSAGE}
	@echo "********************************************************"
	@echo ""
	@echo "* Compiling..."
	@echo "----------------------------------------"
	${CPP} ${CPP_CONSOLE_FLAGS} ${CPP_FLAGS} ${CPP_SOURCES} -c

${CC_OBJECTS}: ${CC_SOURCES}
	${CPP} ${CC_FLAGS} ${CC_SOURCES}

${CC_SOURCES}:${CC_LEXER} ${CC_PARSER}
	${CP} ${SRC}/${CPP_HEADER} .
	${LEX} ${CC_LEXER}
	${YACC} -d ${CC_PARSER}	

install: 
	@echo "----------------------------------------"
	@echo "* Installing..."
	@echo "----------------------------------------"
	${CP} ${BIN}/${APP} ${DEST}

count:
	./${CLOC} . ${SRC} ${LIB} ${CLOC_FLAGS}

clean:
	@echo "----------------------------------------"
	@echo "* Cleaning up..."
	@echo "----------------------------------------"
	${RM} ${APP} *.o *.c *.h

#------------------------------------------
# Finita la musica, passata la fiesta...
#------------------------------------------

