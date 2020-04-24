/*This program uses the Newton-Raphson method to find the root of the polynomial
2x^3 − 9x^2 + 12x − 6.*/

#include<stdio.h>
#include<math.h>

//the polynomial. if changed, p1 must also be changed.
double p(double x);

//the derivative
double p1(double x);

//solves polynomial given in function p. guess = initial guess, epsilon = acceptable error
void solve(double guess, double epsilon);

int main(void)
{
    double guess, error;
    
    printf("Initial guess: "); scanf("%lf", &guess);
    printf("Acceptable error: "); scanf("%lf", &error);
    
    solve(guess, error);
}

void solve(double guess, double epsilon)
{
    int number_of_guesses = 0;

    while(fabs(p(guess)) >= epsilon)
    {   number_of_guesses++;
        
        //Stop division by 0 or too many steps
        if(p1(guess) == 0 || number_of_guesses>10000)
        {   printf("Try some other initial guess or acceptable error.\n");
            return;
        }
        
        guess -= p(guess)/p1(guess);
    }

    printf("\nRoot = %lf\nNumber of Guesses = %d\n", guess, number_of_guesses);
}

double p(double x)
{
    return 2*pow(x,3) - 9*pow(x,2) + 12*x - 6;
}

double p1(double x)
{
    return 6*pow(x,2) - 18*x + 12;
}