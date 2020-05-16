/*We define a search function that implements binary search with inputs array(sorted in ascending order), 
left index, right index and value to be searched as inputs.
It returns the index of the value in the array. If value is not found it returns -1.*/

#include<stdio.h>

int search(int *, int, int, int);

int main(void)
{
    int arr[9] = {0,1,2,3,4,5,6,7,8}, value;  //arr must be sorted in ascending order.
    printf("Value = ");
    scanf("%d", &value);
    printf("%d\n", search(arr, 0, 8, value));
}

int search(int *arr, int l, int r, int value)
{
    int m = (r+l)/2;  //finding the middle point of the array.
    
    //Checking whether value is at middle and returning the index.
    if(arr[m] == value)
    {
        return m;
    }

    //Termination: The array has been virtually shortened to a single element, yet the value was not found.
    if(l == r)
    {
        return -1; 
    }
    
    //If value lies to the left.
    if(value < arr[m])
    {
        r = m-1;  //right index is changed.
        return search(arr, l, r, value); //search is implemented on the shorter array.
    }
    
    //If value lies to the right.
    if(value > arr[m])
    {
        l = m+1;  //left index is changed.
        return search(arr, l, r, value); //search is implemented on the shorter array.
    }
}