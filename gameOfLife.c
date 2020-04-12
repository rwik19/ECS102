/*This program implement's Conway's Game of Life.*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<locale.h>
#include<time.h>

#define MAX_R 45
#define MAX_C 105 //Sets size of world
#define N 3000

void create(int[][MAX_C]); //Creates a random world
int valid(int,int); //Checks for validity of indices of a matrix
int neighbour(int [][MAX_C],int,int); //counts number of neighbours
void evolve(int [][MAX_C]);  //evolves the world to next gen
void display(int [][MAX_C]); //displays world

int main(void)
{
    int world[MAX_R][MAX_C];
    
    for(int i=0;i<MAX_R;++i)
    {
        for(int j=0;j<MAX_C;++j)
        {
            world[i][j] = 0;
        }
    }
    create(world);

    while(1)
    {
        display(world);
        evolve(world);
        for(int i=0;i<2*MAX_C;++i)
            printf("-");
        usleep(1000000);
        printf("\e[1;1H\e[2J");
        printf("\n\n\n");
    }
}

void create(int arr[][MAX_C])
{
    int count=0;
    srand(time(0));
    for(int i=0;i<MAX_R;i++)
    {
        for(int j=0;j<MAX_C;j++)
        {
            arr[i][j] = rand()%2;
            if(arr[i][j])
                count++;
            if(count==N)
                return;
        }
    }        
}

int valid(int i, int j)
{
    if(i>=0 && j>=0 && i<MAX_R && j<MAX_C)
        return 1;
    else
        return 0;
}

int neighbour(int arr[][MAX_C], int i, int j)
{
    int count = 0;
    if(valid(i+1,j))
        if(arr[i+1][j])
            count++;
    
    if(valid(i-1,j))
        if(arr[i-1][j])
            count++;
    
    if(valid(i,j+1))
        if(arr[i][j+1])
            count++;
    
    if(valid(i,j-1))
        if(arr[i][j-1])
            count++;
    
    if(valid(i+1,j+1))
        if(arr[i+1][j+1])
            count++;
    
    if(valid(i-1,j+1))
        if(arr[i-1][j+1])
            count++;
    
    if(valid(i+1,j-1))
        if(arr[i+1][j-1])
            count++;
    
    if(valid(i-1,j-1))
        if(arr[i-1][j-1])
            count++;
    
    return count;
}

void evolve(int arr[][MAX_C])
{
    int temp[MAX_R][MAX_C],n,i,j;
    for(i=0;i<MAX_R;i++)
    {
        for(j=0;j<MAX_C;++j)
        {
            n = neighbour(arr,i,j);
            temp[i][j] = arr[i][j];
            if(arr[i][j])
            {
                if(n<2 || n>3)
                    temp[i][j] = 0;
            }
            else if(n==3)
                temp[i][j] = 1;
        }
    }
    for(i=0;i<MAX_R;i++)
        for(j=0;j<MAX_C;j++)
            arr[i][j] = temp[i][j];
}

void display(int arr[][MAX_C])
{
    setlocale(LC_CTYPE, "");
    for(int i=0;i<MAX_R;i++)
    {
        for(int j=0;j<MAX_C;j++)
        {
            if(arr[i][j])
                printf("%lc",0x25a0);
            else
                printf(" ");
            
            printf(" ");
            //printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}