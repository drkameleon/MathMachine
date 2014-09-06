//
// Test18.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "This is Test18 :)";

let i = 1;

loop (i<10)
{
	save i @ "test18.log";
	put "i = ", i;
	let i = i + 1;
}

put "done.";
