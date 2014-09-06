//
// Test29.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "====================================";
put "* Test29.mm";
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
set dMersenne(d) = pow(2,Mersenne(d))-1;

set Catalan(c) =
{
	if (c==0) { ret 2; }
	else
	{
		ret pow(2,Catalan(c-1))-1;
	}
}

put "Give me a number : ";
get number;

put "Mersenne(",number,") = ", Mersenne(number);
// put "dMersenne(",number,") = ", dMersenne(number);
// put "Catalan(",number,") = ", Catalan(number);

put "----------------";
put "done";

