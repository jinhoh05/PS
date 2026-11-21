#include <bits/stdc++.h>
 
using namespace std;
using ll=long long;
int n,k;
ll d=1000000003,DP[1005][1005];
 
ll dynamic(){
    for(ll i=1;i<=n;i++) DP[i][1]=i;
 
    for(ll i=2;i<=n;i++){
        for(ll j=2;j<=n;j++){
            DP[i][j] = (DP[i-2][j-1] + DP[i-1][j]) % d;
        }
    }
 
    return (DP[n-1][k]+DP[n-3][k-1])%d;
}
 
int main()
{
    scanf("%d %d",&n,&k);
 
    if(k==1){
        printf("%d",n);
        return 0;
    }
 
    printf("%lld",dynamic());
 
    return 0;
}