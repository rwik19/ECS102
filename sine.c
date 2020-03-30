/*This program defines a sine function that uses the Taylor Series to calculate sines at very small angles.
Using the Taylor series to calculate sine has certain limitations. However, one may utilise the periodicity
 of sin x to find sines of larger angles.*/

#include<stdio.h>

double sine(double, int);

int main(void)
{
    float x;
    int number_of_terms;
    printf("x (in radians, preferably |x|< 2pi ~ 6) = ");
    scanf("%f", &x);
    printf("Number of terms till which the Taylor series will be calculated(preferably > 100) = ");
    scanf("%d", &number_of_terms);
    printf("sin(%0.3f) = %0.5f\n", x, sine(x, number_of_terms)); //output is formatted to 5 places after decimal.
}

double sine(double x, int n)
{
    double sum = x, term = x;
    for(int i = 2; i<2*n; i+=2)
    {
        term *= -x*x/(i*(i+1));
        sum += term;
    }
    return sum;
}