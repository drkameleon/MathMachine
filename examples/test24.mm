//
// Test24.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "This is Test24 :)";

set factorial(z) =
{
	put "In factorial";
	if (z==0)
	{
		ret 1;	
	}
	else 
	{
		ret z*factorial(z-1);
	}
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

put "1) Find a power";
put "2) Find a factorial";
get choice;

put "Give me a number : ";
get number;

if (choice==1)
{
	put "Result = ", power(number,5);
}
else
{
	put "Result = ", factorial(number);
}

put "done.";
