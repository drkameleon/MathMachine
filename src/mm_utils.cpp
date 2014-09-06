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

MM_UTILS.CPP

*/

#include "mathmachine.h"

void trimString(string& str,char ch)
{
	string::size_type pos = str.find_last_not_of(ch);
	if(pos != string::npos) 
	{
		str.erase(pos + 1);
		pos = str.find_first_not_of(ch);
		
		if (pos != string::npos) str.erase(0, pos);
	}
	else 
	{
		str.erase(str.begin(), str.end());
	}
}

vector<string> split(const char *str, char c = '/')
{
    vector<string> result;

    while(1)
    {
        const char *begin = str;

        while(*str != c && *str)
                str++;

        result.push_back(string(begin, str));

        if(0 == *str++)
                break;
    }

    return result;
}

string getFolderFromPath(char* path)
{
	vector<string> Items = split(path);

	string result = "";

	for (int i=0; i<Items.size()-1; i++)
	{
		result = result + Items[i] + "/";
	}
	
	return result;
}

bool fileExists(string filename)
{
	ifstream inp;

	inp.open(filename.c_str(), ifstream::in);
	inp.close();

	if (inp.fail())
	{
		return false;
	}
	else
	{
		return true;
	}
}
