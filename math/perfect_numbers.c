/*This program prints all perfect numbers between a and b*/

#include<stdio.h>

int isPerfect(int);

int main(void)
{
	int a,b;
	printf("a = "); scanf("%d", &a);
	printf("b = "); scanf("%d", &b);
	
	for(int i=a;i<=b; ++i)
	{
		if(isPerfect(i))
			printf("%d\n", i);
	}	
}

int isPerfect(int n)
{
	int sum = 0;
	for(int i=1; i<=n/2; ++i)
	{
		if(n%i == 0)
			sum += i;
	}
	if(sum == n)
		return 1;
	else
		return 0;
}
