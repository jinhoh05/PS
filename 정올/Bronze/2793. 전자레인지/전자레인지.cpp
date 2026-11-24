#include <bits/stdc++.h>

using namespace std;
int n,k,a,b,c,ans;
int boy[7],girl[7];


int main()
{
    scanf("%d",&n);

    if(n%10>0){
        printf("-1");
        return 0;
    }

    a=n/300;
    n%=300;

    b=n/60;
    n%=60;

    c=n/10;

    printf("%d %d %d",a,b,c);

    return 0;
}