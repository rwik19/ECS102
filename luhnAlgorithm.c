/*Luhn's algorithm is used to do a primary check on the validity of a credit card number.*/

#include<stdio.h>

int sumOfDigits(long n);
int numOfDigits(long n);

int main(void)
{
    long num,x,sum=0,n=0;
    printf("Enter a credit card number: ");
    scanf("%li",&num);
    n=numOfDigits(num);
    if(n<12||n>17)
    {
        printf("This is not a credit card number.\n");
        return 0;
    }
    x = num/10;
    while(x)
    {
        sum+=sumOfDigits(2*(x%10));
        x/=100;
    }
    x=num;
    while(x)
    {
        sum+=sumOfDigits(x%10);
        x/=100;
    }
    if(sum%10==0)
    {
        printf("This is probably a valid credit card number.\n");
    }
    else
    {
        printf("This is not a credit card number.\n");
    }
}

int sumOfDigits(long n)
{
    if(n<10)
    {
        return n;
    }
    return sumOfDigits(n/10) + n%10;
}

int numOfDigits(long n)
{
    if(n/10 == 0)
    {
        return 1;
    }
    return numOfDigits(n/10) + 1;
}