//Input 3 digits and output all possible permutations of the 3 digits.

#include<stdio.h>

void swap(char *x, char *y);
void permute(char *str, int i, int right);

int main(void)
{
    char numbers[4];
    printf("Enter 3 digits: ");
    scanf("%s", numbers);
    
    permute(numbers, 0, 2);
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