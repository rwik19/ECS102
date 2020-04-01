/*This program generates a string of n random integers in [start,end] WITHOUT REPETITION. The string is stored in result array of
size (end-star+1). Memory for result[] must be allocated in advance.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

void uRandom(int start, int end, int n, int result[]);

int main(void)
{
    int result[5];
    uRandom(355,551,5,result);
    for(int i=0;i<5;++i)
    {
        printf("%d  ",result[i]);
    }
    printf("\n");
}

void uRandom(int start, int end, int n, int result[])
{
    int len = end-start+1, r;
    int arr[len];
    srand(time(0));
    for(int i=0; i<n; ++i)
    {
        r = start+rand()%len;
        if(arr[r-start]!=1)
        {
            result[i]=r;
        }
        else
        {
            --i;
        }
        arr[r-start]=1;
    }
}