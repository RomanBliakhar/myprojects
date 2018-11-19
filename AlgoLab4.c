#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int n;
int main()
{
    int N = 100,k;
    int array[N];
     
    printf("size array:");
    scanf("%d",&N);
    if ( N > 100 )
    {
        printf("size array can't be over 100!\n");
        return 1;
    }
     
    printf("0 < rand < :");
    scanf("%d",&k);
     
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        array[i] = 0 + rand() % k;
        printf("%d\t",array[i]);
    }   
     
    printf("\n");
     
    do
    {
        if (array[0] == 0)
        {
            break;
        }
        n++;
    }
    while (array[n] != 0 && n < N); 
     
    for (int i = 0; i < N; i++)
    {
        if(i == n)
        {
            for (int j = n + 1; j < N; j++)
            {
                array[j - 1] = array[j];
            }       
            N--;  
        } 
        printf("%d\t",array[i]);   
    }
   
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0 && i != 0)
        {
            for (int k = N - 1; k != i; k--)
            {
                array[k + 1] = array[k]; 
            }
            array[i + 1] = array [i - 1] + 2; 
            N++;
        }
        printf("%d\t",array[i]);
    }
    
    printf("\n");
    return 0;
}
