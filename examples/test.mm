use primes;

set mersenne(x) = 
{
	ret x*2-1;
}

let i = 1;

loop (i<10) 
{
	if (i!=5)
	{
		put mersenne(i),"\n";
	}
}

ret 2^2^x-1;
