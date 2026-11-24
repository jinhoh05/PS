#include <bits/stdc++.h>

using namespace std;
int a,b,c,ans;

int main()
{
    scanf("%d %d %d",&a,&b,&c);
    b+=c;
    a+=b/60;
    b%=60;
    a%=24;

    printf("%d %d",a,b);

    return 0;
}