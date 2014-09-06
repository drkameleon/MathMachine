//
// Test20.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "This is Test20 :)";

put "Give me a number : ";
get number;

let i = 1;

loop (i<10)
{
	put "i = ", i, " | i*number = ", i*number;
	let i = i + 1;
}

put "done.";
