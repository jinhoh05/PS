#include <bits/stdc++.h>

using namespace std;
int a,b,c,ans;

int main()
{
    scanf("%d %d %d",&a,&b,&c);
    a*=b;
    if(a>c) printf("%d",a-c);
    else printf("0");

    return 0;
}