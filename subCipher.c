//This program uses substitution cipher to encrypt or decrypt a text file.

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

void uRandom(int start, int end, int n, int result[]);
void encrypt(FILE *);
void decrypt(FILE*);

int main(void)
{
    char filename[20], o;
    FILE *f;
    
    printf("Enter file name(.txt format): ");
    scanf("%s", filename);
    f=fopen(filename,"r+");
    
    if(f==NULL)
    {
        printf("File does not exist.\n");
        return 1;
    }

    printf("Encrypt(E)/Decrypt(D)? ");
    scanf("%*c%c",&o);
    o = toupper(o);
    
    switch(o)
    {
        case 'E': encrypt(f);
                  break;
        case 'D': decrypt(f);
                  break;
        default: printf("Invalid input.\n");
    }
    fclose(f);
}

void uRandom(int start, int end, int n, int result[])
{
    int len = end-start+1, r;
    int arr[len];
    srand(time(0));
    for(int i=0; i<n; ++i)
    {
        r = start+rand()%len;
        if(arr[r-start]!=1)
        {
            result[i]=r;
        }
        else
        {
            --i;
        }
        arr[r-start]=1;
    }
}

void encrypt(FILE *f)
{
    int key[26],c;

    //Generate a random key.
    uRandom('a','z',26,key);
    while((c = fgetc(f)) != EOF)
    {
        //Encryption preserves case.
        if(islower(c))
        {
            fseek(f,-1,SEEK_CUR);
            fputc(key[c-'a'],f);
        }
        else if(isupper(c))
        {
            fseek(f,-1,SEEK_CUR);
            fputc(toupper(key[c-'A']),f);
        }
    }
    printf("Your file was successfully encrypted with the key:\n\n");

    //Print the key.
    for(int i=0;i<26;++i)
    {
        printf("%c",key[i]);
    }
    printf("\n\n");
    printf("**IMPORTANT**\nKeep this key safe.\n");

}

void decrypt(FILE *f)
{
    char key[27],c;
    int i;

    //Ask the user to input key.
    printf("\nKey: ");
    scanf("%s",key);
    while((c = fgetc(f)) != EOF)
    {
        if(islower(c))
        {
            for(i=0;i<26;++i)
            {
                if(c==key[i])
                {
                    break;
                }
            }
            fseek(f,-1,SEEK_CUR);
            fputc('a'+i,f);
        }
        else if(isupper(c))
        {
            for(i=0;i<26;++i)
            {
                if(c==toupper(key[i]))
                {
                    break;
                }
            }
            fseek(f,-1,SEEK_CUR);
            fputc('A'+i,f);
        }
    }
    printf("File was succesfully decrypted with the given key.\n\n");
}