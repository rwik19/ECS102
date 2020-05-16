/*This program defines a sine function that uses the Taylor Series to calculate sines at very small angles.
Using the Taylor series to calculate sine has certain limitations. However, one may utilise the periodicity
 of sin x to find sines of larger angles.
 It also compares the output with the sin function in the math.h library.*/

#include<stdio.h>
#include<math.h>

double sine(double);
double radian(double);
double error(double,double);

int main(void)
{
    double x;
    for(int i=0;i<=90;i+=10)
    {
        if(i==0)
        {
            printf("Angle\t\tsin\t\tsine\t\t%%error\n");
        }
        x = radian((double)i);
        //all values are printed correct upto 2 places of decimal.
        printf("%d\t\t%0.2lf\t\t%0.2lf\t\t%0.2lf\n", i, sin(x), sine(x), error(sine(x), sin(x)));
    }
}

double sine(double x)
{
    double sum = x, term = x;
    for(int i = 2; i<2*50; i+=2)
    {
        term *= -x*x/(i*(i+1));
        sum += term;
    }
    return sum;
}

double radian(double degree)
{
    return degree/180 * M_PI;
}

double error(double observed, double actual)
{
    if(actual == 0)
    {
        return 0;
    }
    return fabs(observed-actual)/actual *100;
}