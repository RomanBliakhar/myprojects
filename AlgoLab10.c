#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int *arr,*new_arr,*add,n,m,q;
 
int *array()
{
 
    arr = (int*)malloc(n * sizeof(int));
     
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0 + rand()%20;
    }
    return arr;
}
 
int *new_array()
{
    new_arr = (int*)malloc((n - 1) * sizeof(int));
    for (int i = 0,j = 0; i < n; i++)
    {
        if (i != (m - 1))
        {
            new_arr[j] = arr[i]; 
            if ( j != (n - 1))
            {
                j++;
            }
        }
    }
    free(arr);
    return new_arr;
}
 
int *add_element()
{
    int l;
    add = (int*)malloc(n * sizeof(int));
    printf("get number = ");
    scanf("%d",&l);
     
    for(int i = 0,j = 0; i < n; i++)
    {
        if (i != (q - 1))
        {
            add[i] = new_arr[j];
            j++;
        }
        else
        {
            add[i] = l;
        }
    }
    free(new_arr);
    return add;
}
 
int main()
{
    printf("array's size = ");
    scanf("%d",&n);
    array();
    for(int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
     
    printf("deleted ement number - ");
    scanf("%d",&m);
    new_array();
    for(int i = 0; i < n - 1; i++)
    {
        printf("%d\t",new_arr[i]);
    }
    printf("\n");
     
    printf("key to add - ");
    scanf("%d",&q);
    add_element();
    for(int i = 0; i < n; i++)
    {
        printf("%d\t",add[i]);
    }
    printf("\n");
     
    free(add);
}
