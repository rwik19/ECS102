/*This program defines a function like strcmp in the string.h library calles Strcmp.
Helper functions:
Strlen is a copy of strlen in string.h
Tolower accepts a string and returns a new string produced by converting all upper case letters to lower case 
and keeping the other characters unchanged*/

#include<stdio.h>
#include<stdlib.h>

int Strlen(char*);
char *Tolower(char *);
int Strcmp(char*, char*);

int main(void)
{
    printf("%d\n", Strcmp("Bat","Ball"));
    printf("%d\n", Strcmp("at","Ball"));
    printf("%d\n", Strcmp("Bat","Bat"));
}

int Strlen(char *str)
{
    int i;
    for(i=0; str[i] != '\0'; ++i);
    return i;
}

char *Tolower(char *str)
{
    int n = Strlen(str);
    char* str1 = malloc(n); //allocate memory to store new string.
    for(int i=0;i<=n;++i)
    {
        //Change and copy if char is upper case
        if(str[i]>='A' && str[i]<='Z')
        {
            str1[i] = str[i] + 32;
        }
        //Simply copy
        else
        {
            str1[i] = str[i];
        }
        
    }
    return str1;
}

int Strcmp(char *Str1, char *Str2)
{
    char *str1 = Tolower(Str1);
    char *str2 = Tolower(Str2);
    int n1 = Strlen(str1);
    int n2 = Strlen(str2);
    int flag=1;
    
    for(int i=0; i<n1 && i<n2; ++i)
    {
        //str1 come before str2
        if(str1[i]<str2[i])
        {
            return 1;
        }

        //str1 comes after str2
        else if(str1[i]>str2[i])
        {
            return -1;
        }
    }

    //str1=str2
    return 0;
}