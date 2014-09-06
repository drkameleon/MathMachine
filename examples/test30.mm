//
// Test30.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "====================================";
put "* Test30.mm";
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

set isPrime(p,v) =
{
	let x = 2;
	let pr = 1;
	loop (x<p/2+1)
	{
		if (v==1) { put "X = ", x, " | P = ", p, " | P%X = ", p%x; }

		if (p%x==0) { let pr = 0; }
	
		let x = x+1;
	}
	
	ret pr;
}

put "Give me a number : ";
get number;

put "Prime(",number,") = ", isPrime(number,1);

put "----------------";
put "done";

