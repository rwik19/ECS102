/*Pick a card from a well-shuffled deck of 52 cards and write the output to a file cards_output.txt.
The program terminates when a card is same as the first drawn card. Cards are numbered 0 to 51 in the following order:
A of Diamonds, K of Diamonds,..., 2 of Diamonds, A of Clubs,..., 2 of Clubs, Spades, ..., Hearts.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    FILE *file;
    int card0, card = -1, i=1; 
    
    //suit = card/13
    char *suit[4] = {"Diamonds", "Clubs", "Spades", "Hearts"};
    
    //rank = card%13; 
    char *rank[13] = {"A", "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
    file = fopen("cards_output.txt", "w");
    srand(time(0));
    card0 = rand()%52;
    fprintf(file, "%d\t\t %s of %s", i++, rank[card0%13], suit[card0/13]);
    while(card != card0)
    {
        srand(time(0)%(19*i));
        card = rand()%52;
        fprintf(file,"\n%d\t\t %s of %s", i++, rank[card%13], suit[card/13]);
        //sleep(1);
    }
    fclose(file);
}