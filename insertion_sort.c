#include<stdio.h>

void insertSort(int *, int);

int main(void)
{
    int arr[8] = {6,8,2,4,1,7,3,5};
    insertSort(arr,8);
    for(int i=0;i<8;++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void insertSort(int *arr, int n)
{
    int x, j;
    for(int i=1;i<n;++i)
    {
        x = arr[i];
        for(j=i; arr[j-1]>x && j>0; --j)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = x;
    }
}