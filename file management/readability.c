//The Coleman-Liau index of a text is designed to output what (U.S.) grade level is needed to understand the text.

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(void)
{
    int words = 0, letters = 0, sentences = 0, d = 1;
    float index, L, S;
    char c, filename[20];
    
    printf("Enter file name(.txt format): ");
    scanf("%s", filename);
    f=fopen(filename,"r");
    
    if(file == NULL)
    {
        printf("File does not exist.\n");
        return 1;
    }
    
    while((c = fgetc(file)) != EOF)
    {
        c = tolower(c);
        if(c==' ')
        {
            d = 1;
        }
        else if(c>='a' && c<='z')
        {
            letters++;
            /*If we have a letter then what was the character just before it?
            If it was a letter or a hyphen, then we have no new word*/
            if(d)
            {
                words++;
            }
            d = 0;
        }
        else if(c=='-')
        {
            d = 0;
        }
        else
        {
            d = 1;
            //Number of sentences ~ number of '!', '?' and '.' in the text.
            if(c=='.'||c=='?'||c=='!')
            {
                sentences++;
            }
        }
    }
    fclose(file);

    L = (float)letters/words*100;  //the average number of letters per 100 words in the text
    S = (float)sentences/words*100;  //the average number of sentences per 100 words in the text
   
    //Calculating Coleman-Liau index of the text.
    index = 0.0588 * L - 0.296 * S - 15.8;

    printf("Words = %d\nLetters = %d\nSentences = %d\n",words,letters, sentences);
    if(index<1)
    {
        printf("Before Grade 1\n");
    }
    else if(index>16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n",index);
    }
}
