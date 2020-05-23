//prints all Pythagorean triplets between a and b
#include<stdio.h>
#include<math.h>

void pythaTriple(int a, int b)
{
    int x,y,n=1;
    float z;
    for(x = a;x*x*2<=b*b;x++)
    {
        for(y = x;x*x+y*y<=b*b;y++)
        {
            count++;
            z = sqrt(x*x+y*y);
            if(z-(int)z == 0)
                printf("%d\t%d,%d,%d\n",n++,x,y,(int)z);
        }
    }
}

int main(void)
{
    pythaTriple(100,1000);
}
