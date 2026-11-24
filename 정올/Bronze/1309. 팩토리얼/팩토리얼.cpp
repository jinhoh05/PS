#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long int n;
    long long int sum=1;

    scanf("%lld",&n);

    for(int i=n;i>1;i--){
        sum=sum*i;
        printf("%d! = %d * %d!\n",i,i,i-1);
    }

    printf("1! = 1\n");
    printf("%lld",sum);

    return 0;
}