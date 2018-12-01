#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct
{
    char name[40];
    char post[40];
    int date;
    int salary;
}EMPLOYEE;
 
int size,k = 0;
 
void write()
{
    FILE *file = fopen("list.txt","wb");
    EMPLOYEE str;
     
    for (int i = 0; i < size; i++)
    {
        printf("name: "); 
        scanf("%s",str.name);
        printf("post: "); 
        scanf("%s",str.post);
        printf("date: "); 
        scanf("%d",&str.date);
        printf("salary: "); 
        scanf("%d",&str.salary);
        fwrite(&str, sizeof(EMPLOYEE), 1, file);
        printf("\n");
    }
    fclose(file);
}
 
void del()
{
    FILE *file = fopen("list.txt","rb");
    FILE *fake = fopen("buffer.txt","wb");
    EMPLOYEE str;
     
    if((file = fopen("list.txt","rb")) == NULL) exit(2);
     
    char nm[40];
    printf("delleted: ");
    scanf("%s",nm);
     
    for (int i = 0; i < size; i++)
    {
        fread(&str, sizeof(EMPLOYEE), 1, file);
        fwrite(&str, sizeof(EMPLOYEE), 1,fake);
    }
    remove("list.txt");
    fclose(file);
    fclose(fake);
     
    fake = fopen("buffer.txt","rb"); 
    file = fopen("list.txt","wb"); 
    for (int i = 0; i < size; i++)
    {
        fread(&str, sizeof(EMPLOYEE), 1, fake);
        if (strcmp(nm,str.name) != 0)
        {
            fwrite(&str, sizeof(EMPLOYEE), 1,file);
        }
        else
        {
            k++;
        }
    }
    remove("buffer.txt");
    fclose(file);
    fclose(fake);   
}
 
void print()
{
    FILE *file = fopen("list.txt","rb");
    EMPLOYEE str;
     
    if((file = fopen("list.txt","rb")) == NULL) exit(1);
   
     
    printf("\n");
    for (int  i = 0; i < size - k; i++)
    {
        fread(&str, sizeof(EMPLOYEE), 1, file);
        printf("name: %s",str.name);       
        printf("\npost: %s",str.post);
        printf("\ndate: %d",str.date);
        printf("\nsalary: %d",str.salary);
        printf("\n\n");
    }
    fclose(file);
}
void bias()
{
    FILE *file = fopen("list.txt","rb");
    FILE *fake = fopen("buffer.txt","wb");
    EMPLOYEE str;
     
    int b;
    printf("bias element: ");
    scanf("%d",&b);
     
    for (int i = 0;i < b; i++)
    {
        fread(&str, sizeof(EMPLOYEE), 1,file);   
        fwrite(&str, sizeof(EMPLOYEE), 1, fake); 
    }
    fclose(fake);
     
    fake = fopen("buffer.txt","ab");
    printf("name: "); 
    scanf("%s",str.name);
    printf("post: "); 
    scanf("%s",str.post);
    printf("date: "); 
    scanf("%d",&str.date);
    printf("salary: "); 
    scanf("%d",&str.salary);
    fwrite(&str, sizeof(EMPLOYEE), 1, fake);
    fclose(fake);
    k--;
 
    fake = fopen("buffer.txt","ab");
 
    for (int i = b + 1; i < size; i++)
    {   
        fread(&str, sizeof(EMPLOYEE), 1,file);
        fwrite(&str, sizeof(EMPLOYEE), 1, fake);  
    }
    remove("list.txt");
    fclose(file);
    fclose(fake);
     
    fake = fopen("buffer.txt","rb"); 
    file = fopen("list.txt","wb");
    for (int i = 0; i < size; i++)
    {
        fread(&str, sizeof(EMPLOYEE), 1, fake);
        fwrite(&str, sizeof(EMPLOYEE), 1, file);
    }
    remove("buffer.txt");
    fclose(file);
    fclose(fake);
}
 
int main()
{
    printf("get list's size: ");
    scanf("%d",&size); 
     
    write();
    del();
    print();
    bias();
    printf("\n***bias***\n");
    print();  
}
