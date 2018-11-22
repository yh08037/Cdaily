#include <stdio.h>

int d(int n);

int list[10000];

int main(void)
{	
	int i;
	for(i=0; i<10000; i++)
	{
		list[d(i)] = 1;
		if(!list[i]) printf("%d\n", i);	
	}
		
	return 0;
}

int d(int n)
{
	int i, sum=n;
	for(i=0; i<4; i++)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}
