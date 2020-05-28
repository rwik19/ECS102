/*This program print the sum of the series 1+11+111+... n times*/
#include<stdio.h>

int main(void)
{
	int n, term = 0, sum = 0;
	printf("n = "); scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		term = term*10 + 1;
		sum += term;	
	}
	printf("S(%d) = %d\n", n, sum);	
}
