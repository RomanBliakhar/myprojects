#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#define maxlenght 255
char buffer[maxlenght];   
 
void write()
{
    FILE *file1 = fopen("file1.txt","w");
     
    for (int i = 0; i < 5;i++)
    {
        fgets(buffer, maxlenght,stdin);
        if(buffer[strlen(buffer) - 1] != '\n')
        {
            buffer[strlen(buffer)] = '\n';
            buffer[strlen(buffer) + 1] = '\0';
        }
        fputs(buffer, file1);
    }
    rewind(file1);
    fclose(file1);
    printf("\n****print****\n");
    file1 = fopen("file1.txt","r");
    while ((fgets(buffer, maxlenght,file1)) != NULL)
    {
        printf("%s",buffer);  
    }
    rewind(file1);
    fclose(file1);
     
}
 
void copy_file()
{
    FILE *file1 = fopen("file1.txt","r");
    FILE *file2 = fopen("file2.txt","w");
    int i;
    for (i = 0; i < maxlenght; i++)
    {
        if(isalpha(buffer[i]))
        {
            break;
        }
    }
    while ((fgets(buffer, maxlenght, file1)) != NULL)
    {
        if(buffer[i] == 'a' || buffer[i] == 'A')
        {   
            fgets(buffer, maxlenght + 1, file1);
            fputs(buffer, file2);
        }
    }
    fclose(file2);
    file2 = fopen("file2.txt","r");
    while ((fgets(buffer, maxlenght,file2)) != NULL)
    {
        printf("%s",buffer);  
    }
    rewind(file2);
    fclose(file1);
 
}
void word_count()
{
    FILE *file2 = fopen("file2.txt","r");
     
    int j = 0;
    while ((fgets(buffer, maxlenght,file2)) != NULL)
    {
        int k = 0;
        for (int i = 0; buffer[i] != '\0' ; i++)
        {
            if (buffer[i] != ' ' && buffer[i + 1] != '\0')
            {
                k++;
            }
            else
            {
                if(k != 0)
                {
                    j++;
                    k = 0;
                }
            }
        } 
    }
    printf("%d\n",j);
    fclose(file2);
}
 
 
int main()
{
         
    printf("write:\n");
    write();
    printf("\n***WITHUT LETTER 'A'***\n");
    copy_file();
    printf("\n***count lerrer***\n");
    word_count();
 
}
