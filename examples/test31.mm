//
// Test31.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "====================================";
put "* Test31.mm";
put "* By Dr.Kameleon";
put "====================================";

set isPrime(p) =
{
	let x = 2;
	let pr = 1;
	loop (x<p/2+1)
	{
		if (p%x==0) { let pr = 0; }
	
		let x = x+1;
	}

	if (p==2) { let pr = 1; }
	
	ret pr;
}

set getPrimePairs(z) =
{
	let i = 6;

	loop (i<z)
	{
		let nof = 0;
		let k = 2;
		loop (k<=i/2)
		{
			if (isPrime(k)==1)
			{
				if (isPrime(i-k)==1)
				{
					let nof = nof + 1;
				}
			}
			let k = k +1;
		}
		
		save i, ",", nof, "," @ "test.csv";	// put "i = ", i, " | pairs = ", nof;	

		let i = i + 2;
	}
	ret 0;
}

put "Give me a number : ";
get number;

put getPrimePairs(number);

put "----------------";
put "done";

