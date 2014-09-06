//
// Test22.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "This is Test22 :)";

let i = 1;

set mul(x,y) = x*y;

loop (i<10)
{
	put "i = ", i, " /// i*2 = ", mul(i,i*i);
	let i = i + 1;
}

put "done.";
