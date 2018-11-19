#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
 
void reshuffle(int p, int q, int arr[p][q])
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p - 1; j++)
        {
            if (arr[i][2] > arr[j][2])
            {
                int b;
                for (int k = 0; k < q; k++)
                {
                    b = arr[j][k];
                    arr[j][k] = arr[i][k];
                    arr[i][k] = b;
                }
            }
        }
    }   
}
 
 
int main(int argc,char *argv[])
    {
    if (argc != 3)
    {   
        return 1;
    }
     
    int N = atoi(argv[1]); 
    int M = atoi(argv[2]);
    int array[N][M];
     
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            array[i][j] = 0 + rand() % 20;
        }
    }
     
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {   
            printf("%d \t",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
     
    reshuffle(N, M, array);
     
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {   
            printf("%d \t",array[i][j]);
        }
        printf("\n");
    }
}
