// =======================================
// Test33.mm
// in MML
//
// Part of the MathMachine Project
//
// Copyright (c) 2009-2011
// By Dr.Kameleon
//========================================

//---------------------------------------
// Oi vasikes synarthseis
//---------------------------------------

// elegxei an o P einai prwtos (mhn aporhseis gia thn ylopoihsh - prepei na lysw prwta ena bug me thn RET :S)
set isPrime(p) =
{
	let isP = 1;
	
	let x = 2;
	loop (x<p/2+1)
	{
		if (p%x==0) { let isP = 0; }
	
		let x = x+1;
	}	

	if (p==2) { let isP = 1; }
	
	ret isP;
}

// ypologizei thn dynamh x^y
set pow(x,y) =
{
	let result = 1;

	let poz = 0;
	loop (poz<y)
	{
		let result = result*x;
		let poz = poz+1;
	}
	
	ret result;
}

// elegxei th diairetothta tou N apo ton D
set isDivisible(n,d) =
{
	if (n%d==0) { ret 1; }
	else { ret 0; }
}

// epistrefei ton X-osto mersenne
set mersenne(x) = pow(2,x)-1;

// ypologizei ta perivohta zeugaria prwtwn pou dinoun athroisma K, opou K kathe artios apo to 2 mexri ton Z
// epishs ta apothikeuei kai se ena arxeio .csv (comma-separated values) - an to ekteleseis p.x. me "put primepairs(1000);" meta mporeis na anoikseis to arxeio 
// test.csv me to Excel kai na ftiakseis kai to grafhmo (ton perivohto komhth tou Goldbach)

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
		
		put "i = ", i, " | pairs = ", nof; 
		 save i, ",", nof, "," @ "test.csv";

		let i = i + 2;
	}
	ret 0;
}

set getContinue(c) =
{
	put "Continue playing with this app? [0-1]";
	get answer;

	if (answer==0)
	{
		ret 0;
	}
	else
	{
		ret 1;
	}
}

//---------------------------------------
// To programma 
//---------------------------------------

exec "clear";

put "====================================";
put "* Test33.mm";
put "* By Dr.Kameleon";
put "====================================";
put "";

let keepGoing=1;

loop (keepGoing==1)
{
	put "Choose an option : ";
	put "1) Check if prime";
	put "2) Find mersenne";
	put "3) Get Prime pairs";
	put "[1-3]";
	get choice;

	put "OK then... Give me a number :";
	get Number;

	if (choice==1)
	{
		put "Checking if ", Number," is a prime :";
		let ispr = isPrime(Number);
		if (ispr==1)
		{
			put "TRUE";
		}
		else
		{
			put "FALSE";
		}
	}
	else
	{
		if (choice==2)
		{
			put "Mersenne(", Number,") = ", mersenne(Number);	
		}
		else
		{
			if (choice==3)
			{
				put "Printing all prime pairs up to ", Number;
				put getPrimePairs(Number);
			}
		}
	}

	let ans = getContinue(1);

	if (ans==0)
	{
		let keepGoing = 0;
	}
}


