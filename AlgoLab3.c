#include <stdio.h>
#include <math.h>
 
double x, y, a = 3.14/5.0, b = 3.14*9.0/5.0, sn, se;
int main()
{
    for( x = a; x <= b; x +=8.0*3.14/50.0)
    {
        se = 0; sn =  0;
        for (int n = 1; n <= 40; n++)
        {
            sn += cos(n * x) / n;
        }
         
        int n = 1;
        do
        {
            se += cos(n * x) / n;
            n++;
        }
        while (fabs(cos(n * x) / n) > 0.0001);
         
        y = -( log( fabs( 2 * sin(x / 2 ))));
         
    printf("X= %lf \tSN = %lf\tSE = %lf\tY = %lf\n", x, sn, se, y);    
    }
}
