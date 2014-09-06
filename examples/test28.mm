//
// Test28.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "====================================";
put "* Test28.mm";
put "* By Dr.Kameleon";
put "====================================";

set pow(x,y) =
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
			ret x*pow(x,y-1);
		}
	}
}

set Mersenne(n) = pow(2,n)-1;

let a = 1;
loop (a<20)
{
	put "Mersenne(",a,") = ", Mersenne(a);
	let a = a + 1;
}

put "----------------";
put "done";
