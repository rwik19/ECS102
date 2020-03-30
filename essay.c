/*This program counts the number of words, letters, vowels and blank spaces in a file named essay.txt located in the same 
directory.*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int isvowel(char);
int isletter(char);
int isBlank(char);

int main(void)
{
    int words = 0, vowels = 0, letters = 0, blanks = 0, d = 1;
    char c;
    FILE *file = fopen("essay.txt", "r");
    if(file == NULL)
    {
        printf("File does not exist.\n");
        return 1;
    }
    while((c = fgetc(file)) != EOF)
    {
        if(isBlank(c))
        {
            blanks++;
            d = 1;
        }
        else if(isletter(c))
        {
            letters++;
            if(isvowel(c))
            {
                vowels++;
            }
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
        }
    }
    fclose(file);
    printf("Words = %d\nLetters = %d\nVowels = %d\nBlank Spaces = %d\n",words,letters,vowels,blanks);
}

int isvowel(char c)
{
    c = tolower(c);
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    {
        return 1;
    }
    return 0;
}

int isletter(char c)
{
    c = tolower(c);
    if(c>='a' && c<='z')
    {
        return 1;
    }
    return 0;
}

int isBlank(char c)
{
    if(c==' ')
    {
        return 1;
    }
    return 0;
}