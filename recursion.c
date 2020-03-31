#include<stdio.h>
#include<string.h>
//Prints first n even natural numbers.
void printEven(int n)
{
    if(n>0)
    {
        printEven(n-1);
        printf("%d  ", 2*n);
    }
}

//Returns x^y where y is a whole number.
double power(float x, int y)
{
    if(y==0)
    {
        return 1;
    }
    return x*(power(x,y-1));
}

//Returns factorial of a positive integer.
long Fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return Fact(n-1)*n;
}

//Returns sum of first n odd natural numbers.
int sumOdd(int n)
{
    if(n==1)
    {
        return 1;
    }
    return sumOdd(n-1)+2*n-1;
}


//Returns the nth term of Fibonacci sequence.
long fibo(int n)
{
    if(n==1 || n==2)
    {
        return 1;

    }
    return fibo(n-2) + fibo(n-1);
}

//Returns the number of digits in an integer.
int numOfDigits(int n)
{
    if(n/10 == 0)
    {
        return 1;
    }
    return numOfDigits(n/10) + 1;
}

//Returns the sum of digits of a whole number.
int sumOfDigits(int n)
{
    if(n<10)
    {
        return n;
    }
    return sumOfDigits(n/10) + n%10;
}

//Returns the gcd of two positive integers.
int gcd(int x, int y)
{
    if(x%y==0)
    {
        return y;
    }
    return gcd(y,x%y);
}

//Returns 1 if the string is a palindrome. Else returns 0.
int isPalindrome(char *str, int start)
{
    int end = strlen(str) - start - 1;
    if(str[start] != str[end])
    {
        return 0;
    }
    if(start==end || start==end-1)
    {
        return 1;
    }
    return isPalindrome(str, start+1);
}

//Converts a decimal(positive integer) to binary.
long binary(int n)
{
    if(n==0)
    {
        return 0;
    }
    return binary(n/2)*10 + n%2;
}

int main(void)
{
    return 0;
}