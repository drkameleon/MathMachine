//
// Test25.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

//-----------------------------
// The Functions
//-----------------------------

set factorial(z) =
{
	if (z==0) { ret 1; }
	else { ret z*factorial(z-1); }
}

set power(x,y) =
{
	if (y==0)
	{
		ret 1;
	}
	else
	{
		if (y==1)
		{
			ret x;
		}
		else
		{
			ret x*power(x,y-1);
		}
	}
}

//-----------------------------
// The Main App
//-----------------------------

exec "clear";

put "====================================";
put "* Power/Factorial Calculator";
put "* Coded in MML";
put "*";
put "* Copyright (c) 2010";
put "* By Dr.Kameleon";
put "====================================";

put "------------------------------";
put "|        MENU";
put "------------------------------";
put "| 1 > Calculate Power";
put "| 2 > Calculate Factorial";
put "|-----------------------------";
put "| Choose an option [1-2] :";

get option;

if (option==1)
{
	put "Let's calculate the power x^y then...";
	put "Give me X : ";
	get X;
	put "Give me Y : ";
	get Y;
	put "================================";
	put "* ", X, "^", Y, " = ", power(X,Y);
	put "================================";
}
else 
{ 
	if (option==2) 
	{
		put "Let's calculate the factorial x! then...";
		put "Give me X : ";
		get X;
		put "================================";
		put "* ",X,"! = ", factorial(X,Y);
		put "================================";
	}
	else 
	{
		put "Wrong option! :-(";
	}
}

put "Thanks for playing with me!";
put "C'ya later, alligator! :-)";

//===========================================
// This is the end,
// 	my only friend, the end...
//===========================================

