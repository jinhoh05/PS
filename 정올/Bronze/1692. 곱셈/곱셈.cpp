#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    int m;
    int a,b,c;
    scanf("%d %d",&n,&m);
    a = m % 10;
    b = m % 100 - a;
    c = m - b - a;

    printf("%d\n",n * a);
    printf("%d\n",n * b / 10);
    printf("%d\n",n * c / 100);
    printf("%d",(n * a) + (n * b) + (n * c));


    return 0;
}