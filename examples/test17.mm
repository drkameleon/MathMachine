//
// Test17.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "This is Test17 :)";

set mul10(x) = 10 * x;

let i = 1;

loop (i<10)
{
	put "before mul";
	put "mul10 = ", i*10;
	put "after mul";
	let i = i+1;
}

put "done.";
