/*This program prints a pyramid of given height. Eg, for height=4 we get
   #   #
  ##   ##
 ###   ###
####   ####
*/

#include<stdio.h>

int main(void)
{
    int height;
    printf("Height: ");
    scanf("%d",&height);
    for(int i=1;i<=height;++i)
    {
        for(int j = 1;j<=height-i;++j)
        {
            printf(" ");
        }
        for(int j = 1;j<=i;++j)
        {
            printf("#");
        }
        printf("\t");
        for(int j = 1;j<=i;++j)
        {
            printf("#");
        }
        printf("\n");
    }
}