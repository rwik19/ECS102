/*The function bubbleSort implements bubble sort on an array of ints and sorts them in increasing order.
A flag is implemented to check if the array is already sorted for faster average runtime.*/
#include<stdio.h>

void swap(int *, int*);
void bubbleSort(int *, int);

int main(void)
{
    int arr[8] = {8,7,6,5,4,3,2,1};
    bubbleSort(arr,8);
    /*for(int i=0;i<8;++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");*/
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n)
{
    int flag = 1;
    for(int i=0; i<n-1 && flag; ++i)
    {
        flag = 0;
        for(int j=0; j<n-i-1; ++j)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr+j, arr+j+1);
                flag = 1;
            }
        }
        for(int k=0;k<n;++k)
        {
            printf("%d  ", arr[k]);
        }
        printf("\n");
    }
}