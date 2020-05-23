//Input n digits and output all possible permutations of the n digits.

#include<stdio.h>
#include<string.h>

#define MAX 10

void swap(char *x, char *y);
void permute(char *str, int left, int right);

int main(void)
{
    char numbers[MAX];
    printf("Enter n digits: ");
    scanf("%s", numbers);
    int n = strlen(numbers);
    
    permute(numbers, 0, n-1);
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int left, int right)
{
    if (left == right)
        printf("%s\n", str);
    else 
    {
        for (int j = left; j <= right; j++)
        {
            swap((str + left), (str + j));
            permute(str, left + 1, right);
            swap((str + left), (str + j)); //backtrack
        }
    }
}
