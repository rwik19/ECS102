#include<stdio.h>
#include<math.h>

int isprime(int);

int main(void)
{
    int n;
    printf("Enter a natural number greater than 1: ");
    scanf("%d", &n);
    if(isprime(n) == 1)
    {
        printf("%d is prime.\n", n);
    }
    else if(isprime(n) == 0)
    {
        printf("%d is not prime.\n", n);
    }
    else if(isprime(n) == -1)
    {
        printf("%d < 2.\n", n);
    }
}

int isprime(int n)
{
    int s = sqrt(n), i;
    if(n < 2)
    {
        return -1;
    }
    for(i = 2; i <= s; ++i)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}