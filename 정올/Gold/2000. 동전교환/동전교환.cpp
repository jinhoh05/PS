#include <bits/stdc++.h>

using namespace std;
int n,w;
int coin[15];
int dp[65000];
int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&coin[i]);
    }

    scanf("%d",&w);
    dp[0]=0;

    for(int i=1;i<=w;i++){
        dp[i]=100000;
        for(int j=1;j<=n;j++){
            if(coin[j] <= i){
                if(dp[i-coin[j]] < dp[i]) dp[i]=dp[i-coin[j]]+1;
            }
            else break;
        }
    }
    
    if(dp[w]==100000) printf("impossible");
    else printf("%d",dp[w]);

    return 0;
}