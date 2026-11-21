#include <bits/stdc++.h>
 
using namespace std;
 
int weight[31];
int m[3] = {-1, 0, 1};
int dp[35][40005];
 
int main()
{
    int n,t;
    scanf("%d", &n);
 
    for(int i = 1; i <= n; i++) scanf("%d",&weight[i]);
 
    dp[0][15000] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<=30000;k++){
                t = weight[i] * m[j] + k;
                dp[i][t] += dp[i-1][k];
            }
        }
    }
 
 
    int m,r;
 
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d", &r);
        if(dp[n][r+15000]) printf("Y ");
        else printf("N ");
    }
 
    return 0;
}