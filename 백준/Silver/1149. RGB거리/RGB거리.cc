#include <bits/stdc++.h>

using namespace std;
int n;
int DP[1005][5], cost[1005][5];

int dynamic(){
    for(int i=1;i<=n;i++){
        DP[i][1] = min(DP[i - 1][2], DP[i - 1][3]) + cost[i][1];
        DP[i][2] = min(DP[i - 1][1], DP[i - 1][3]) + cost[i][2];
        DP[i][3] = min(DP[i - 1][1], DP[i - 1][2]) + cost[i][3];
    }

    return min({DP[n][1], DP[n][2], DP[n][3]});
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&cost[i][j]);
        }
    }

    printf("%d", dynamic());

    return 0;
}

