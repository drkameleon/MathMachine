//
// Test32.mm
// Example Script in MML
//
// Copyright (c) 2011
// By Dr.Kameleon
//

put "====================================";
put "* Test32.mm";
put "* By Dr.Kameleon";
put "====================================";

set sqr(x) =
{
	put "before ret";

	ret x*x;

	put "after ret";
}

put "Give me a number : ";
get number;

put sqr(number);

put "----------------";
put "done";

