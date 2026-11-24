#include <bits/stdc++.h>

using namespace std;
long long int n,m,a;
long long int si,ei;
long long int hap[1000005];

int main()
{
    scanf("%lld",&n);

    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        hap[i]=hap[i-1]+a;
    }

    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        scanf("%lld %lld",&si,&ei);
        printf("%lld\n",hap[ei]-hap[si-1]);
    }

    return 0;
}