#include <stdio.h>

using namespace std;

int main()
{
    double n,x=0;
    scanf("%lf", &n);
    while(1) {
        scanf("%lf", &x);
        if(x==999) break;
        printf("%.2lf\n", x-n);
        n=x;
    }
    
    return 0;
}