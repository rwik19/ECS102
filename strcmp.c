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
    char* str1 = malloc(n);
    for(int i=0;i<=n;++i)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str1[i] = str[i] + 32;
        }
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
    
    /*if(n1 == n2)
    {
        for(int i=0; i < n1; ++i)
        {
            if(str1[i] != str2[i])
            {
                flag = 0; 
            }
        }
        if(flag)
        {
            return 0;
        }
    }*/
    for(int i=0; i<n1 && i<n2; ++i)
    {
        if(str1[i]<str2[i])
        {
            return 1;
        }
        else if(str1[i]>str2[i])
        {
            return -1;
        }
    }
    return 0;
}