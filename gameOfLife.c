/*This program implement's Conway's Game of Life.*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <locale.h>

#define MAX 20 //Sets size of world

void create(int[][MAX]); //Creates a random world
int valid(int,int); //Checks for validity of indices of a matrix
int neighbour(int [][MAX],int,int); //counts number of neighbours
void evolve(int [][MAX]);  //evolves the world to next gen
void display(int [][MAX]); //displays world

int main(void)
{
    int world[MAX][MAX];
    create(world);
    while(1)
    {
        display(world);
        evolve(world);
        for(int i=0;i<2*MAX;++i)
            printf("-");
        printf("\n\n\n");
        usleep(800000);
        printf("\e[1;1H\e[2J");
    }
}

void create(int arr[][MAX])
{
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            arr[i][j] = rand()%2;
}

int valid(int i, int j)
{
    if(i>=0 && j>=0 && i<MAX && j<MAX)
        return 1;
    else
        return 0;
}

int neighbour(int arr[][MAX], int i, int j)
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

void evolve(int arr[][MAX])
{
    int temp[MAX][MAX],n,i,j;
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;++j)
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
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            arr[i][j] = temp[i][j];
}

void display(int arr[][MAX])
{
    setlocale(LC_CTYPE, "");
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
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
