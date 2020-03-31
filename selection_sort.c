#include<stdio.h>

void swap(int *, int *);
void selectSort(int *, int);

int main(void)
{
    int arr[8] = {6,8,2,4,1,7,3,5};
    selectSort(arr,8);
    for(int i=0;i<8;++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectSort(int *arr, int n)
{
    int min, pos;
    for(int i=0;i<n-1;++i)
    {
        min = arr[i];
        pos = i;
        for(int j=i+1;j<n;++j)
        {
            if(arr[j]<min)
            {
                min = arr[j];
                pos = j;
            }
        }
        swap(arr+pos, arr+i);
    }
}