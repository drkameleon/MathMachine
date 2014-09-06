//
// Test27.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "====================================";
put "* Test27.mm";
put "* By Dr.Kameleon";
put "====================================";

set isDivisible(n,d) =
{
	if (n%d==0) { ret 1; }
	else { ret 0; }
}

set isPrime(p) =
{
	put "in isPrime : testing :: ", p;

	let i = 2;
	let prime = 1;
	loop (i<p/2)
	{
		if (isDivisible(p,1)==1)
		{
			let prime = 0;
		}			
	}

	ret prime;
}

put "Give me a number (A) :";
get a;
put "Give me a number (B) :";
get b;

let isp = isDivisible(a,b);

if (isp==1)
{
	put "> ", a, " IS divisible by ",b;
}
else
{
	put "> ", a, " is NOT divisible by ",b;
}

put 31;
