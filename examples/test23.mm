//
// Test23.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "This is Test23 :)";

put "2+1 = ", 2+1;

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

put "Give me a number : ";
get number;

put "Factorial(", number, ") = ", factorial(number);

put "done.";
