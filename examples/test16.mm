//
// Test16.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "This is Test16 :)";

let i = 1;

set add(x,y) = x + y;

loop (i<10)
{
	put "10 % i = ", 10 % i;
	put "1+2 = ",add(1,2);
	let i = i+1;
}

put "done.";
