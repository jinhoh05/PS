#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000;

int n;
int DP[505][505];
int dist[505], spring[505], hold[505];

int dynamic()
{
    DP[1][1] = 1;
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            int st = max(i, j) + 1;
            
            for(int k = st; k <= n; k++){
                if(dist[i] + spring[i] >= dist[k]){
                    DP[k][j] += DP[i][j];
                    if(DP[k][j] > MOD) DP[k][j] -= MOD;
                }
            }
            
            for(int k = st; k <= n; k++){
                if(hold[j] && dist[j] + spring[k] >= dist[k]){
                    DP[i][k] += DP[i][j];
                    if(DP[i][k] > MOD) DP[i][k] -= MOD;
                }
            }
        }
    }
    
    int ans = 0;
    
    for(int i = n - 1; i > 0; i--){
        if(dist[i] + spring[i] >= dist[n]) ans += DP[i][n];
    }
    
    return ans % MOD;
}

void input()
{
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", dist + i, spring + i, hold + i);
    }
}

int main()
{
    input();
    
    printf("%d", dynamic());
    
    return 0;
}
