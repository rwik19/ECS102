/*This program reads a dna fasta file and counts the number of G nucleotides. It also calculates the average space
between consecutive Gs in the sequence*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE *file = fopen("dna.fna", "r");
    char c;
    
    //d measures the space between two consecutive Gs.
    int d=-1, n = 0, sum = 0;
    float avg;
    if(file == NULL)
    {
        printf("File does not exist.\n");
        return 1;
    }
    while((c=fgetc(file)) != EOF)
    {
        if(c=='G')
        {
            //Is this the first G? Then don't change sum.
            if(d==-1)
            {
                d = 0;
                n++;
            }
            //If it is not the first G, then add d to sum. Reinitialize d to start counting spaces again.
            else
            {
                sum+=d;
                n++;
                d=0;
            }
        }
        //Ignore new lines. Also don't start measuring space until we find the first G.
        else if(d!=-1 && c!='\n')
        {
            d++;
        }
    }
    printf("Number of Gs = %d\n", n);
    avg = (float)sum/n;
    printf("Avg space between consecutive appearance of G = %0.4f\n", avg);
}