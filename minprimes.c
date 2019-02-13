#include <stdio.h>
#define MAXNUMB 100000000
int main(void)
{
	unsigned long i, a, subseq, q;
	unsigned int diairetes, ypakol, minprime, k, mask;
	
	
	for (i=11; i<MAXNUMB; i+=2)//step +2 because even numbers are not primes
	{
		//faster run begin
		//discard the numbers that include one of the one-digit primes (2,3,5,7)
		minprime=1;
		a=i;
		while (a && minprime)
		{
			if (a%10==2 || a%10==3 || a%10==5 || a%10==7) minprime=0;                                                                             
			a/=10;
		}
		//faster run end
		
		if (minprime)
		{ 
			diairetes=0;
			for (a=2 ; diairetes==0 && a*a<=i ; a++) // check if prime
				if (i%a==0)
					diairetes++;
			
			if (diairetes==0)
			{
				ypakol=1;
				for (a=i; a; a/=10) //find number of subsequences of i
					ypakol*=2;
				
				for (k=1;minprime && k<ypakol-1; k++) //find every subsequence and check if prime
				{
					subseq=0;
					q=1;
					mask=k;
					for (a=i;mask && a; a/=10) //subsequence construction
					{
						if (mask%2)
						{
							subseq+=q*(a%10);	//subseq: the subsequence that is being constructed
							q*=10;
						}
						mask/=2;
					}
					
					diairetes=0;
					for (a=2;diairetes==0 && a*a<=subseq; a++) //check if prime
						if (subseq%a==0)
							diairetes++;
					
					if (diairetes==0 && subseq != 1 && subseq !=0) // 0 and 1: special
						minprime=0; //if subseq is prime, i is not minprime
				}
				if (minprime)
				  printf ("%8ld\n", i);
			}
		}
	}
	return 0;
}
