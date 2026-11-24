#include <bits/stdc++.h>

using namespace std;

int weight[1005];
int price[1005];
int dp[1005][10005];

int main(){
    int n,w;
    scanf("%d %d",&n,&w);

    for(int i=1;i<=n;i++){
        scanf("%d %d",&weight[i], &price[i]);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(weight[i] > j){
                dp[i][j] = dp[i-1][j];
            }
            else if(weight[i] <= j){
                dp[i][j] = max(dp[i-1][j], price[i] + dp[i-1][j-weight[i]]);
            }
        }
    }

    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/

    printf("%d",dp[n][w]);

    return 0;
}