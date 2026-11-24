#include <bits/stdc++.h>

using namespace std;
int n,m,cnt,hap,ans;
int notprime[10005];

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int main()
{
    scanf("%d %d",&n,&m);

    int ans=gcd(n,m);
    printf("%d\n%d",ans,n/ans*m);

    return 0;
}