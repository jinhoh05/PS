#include <stdio.h>
#include <math.h>

int main()
{
    double a;
    scanf("%lf", &a);
    
    double value = a * a * sqrt(3)/4;
    printf("%.10lf", value);
    return 0;
}