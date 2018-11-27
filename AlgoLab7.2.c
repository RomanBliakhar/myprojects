#include <stdio.h>
#include <stdarg.h>
 
float mult(int n,...)
{
    float result = 1.0;
    va_list factor;
    va_start(factor,n);
    for (int i = 0; i < n; i++)
    {
        result *= va_arg(factor,double);
    }
    va_end(factor);
    return result;  
} 
int main()
{
    printf("%f\n",mult(3, 2.5, 7.3, 1.0));
    printf("%f\n",mult(7, 0.23, 1.7, 2.0, 3.71, 2.5, 7.3, 1.0));
    printf("%f\n",mult(11, 1.1, 6.02, 0.01, 1.12, 0.23, 1.7, 2.0, 3.71, 2.5, 7.3, 1.0));    
}  
