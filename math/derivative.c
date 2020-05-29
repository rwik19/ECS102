/*This program tries to approximate the derivative of a function at a point*/

#include<stdio.h>
#include<math.h>
#define h 0.00001

double f(double x) //define a differentiable function
{
	return sin(x);
}

double der(double a) //derivative of f at a
{
	return (f(a+h)-f(a))/h;
}

int main(void)
{
	double a;
	a = 4;
	printf("f\'(a) = %lf\n", der(a));
}
