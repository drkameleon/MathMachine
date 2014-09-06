//
// Test15.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "This is Test15 :)";

set sqr(x) = x*x;

let i = 3;

loop (i<10)
{
	put "i = ", i;
	put "sqr = ",sqr(i);
	let i = i+1;
}

put "sqr(2) = ", sqr(2);
put "sqr(3) = ", sqr(3);

put "done.";
