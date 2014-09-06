//
// Test21.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "This is Test21 :)";

set mersenne(x) = {
	ret 2^x-1;
}

put "Give me a number : ";
get number;

let i = 1;

loop (i<10)
{
	put "i = ", i, " | mersenne(i) = ", mersenne(i);
	let i = i + 1;
}

put "done.";
