/*This program defines a function reverse that takes an int and returns its reverse.*/

#include<stdio.h>

int reverse(int);

int main(void)
{
    int number;
    printf("Enter a natural number: ");
    scanf("%d", &number);
    printf("Reverse of %d is %d\n", number, reverse(number));
}

int reverse(int n)
{
    int reverse = 0;
    while(n)
    {
        reverse *= 10;
        reverse += n % 10;  //Extract last digit from n and add to reverse.
        n /= 10; //remove last digit from n.
    }
    return reverse;
}