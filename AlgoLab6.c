#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
 
void shortest_word(char arr[])
{
    int len = 0, min = 0, max = 0, i = 0;
    for (i = 0; arr[i] != '.'; i++)
    {
        if (isalpha(arr[i]))
        {
            len++;
        }
        else
        {
            if ((len < max || max == 0) && len != 0)
            {
                max = len;
                min = i - len;
            }
            len = 0;
        }
    }
    if (len < max)
    {
        max = len;
        min = i - len;   
    }
     
    max += min;
    for (int j = min; j < max; j++)
    {
        printf("%c",arr[j]);
    }
    printf("\n");
} 
 
void longest_word(char arr[])
{
    int len = 0, min = 0, max = 0, i = 0;
    for (i = 0; arr[i] != '.'; i++)
    {
        if (isalpha(arr[i]))
        {
            len++;
        }
        else
        {
            if (len > max)
            {
                max = len;
                min = i - len;
            }
            len = 0;
        }
    }
    if (len > max)
    {
        max = len;
        min = i - len;   
    }
     
    max += min;
    for (int j = min; j < max; j++)
    {
        printf("%c",arr[j]);
    }
    printf("\n");
} 
 
int main()
{ 
    char str_arr[] = "core isdsd   aaalore dlfdl   df.";
    printf("the shortest word is: ");
    shortest_word(str_arr);
    printf("the longest word is: ");
    longest_word(str_arr);
}
