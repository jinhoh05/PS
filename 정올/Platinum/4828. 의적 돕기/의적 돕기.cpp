#include <bits/stdc++.h>

using namespace std;

int n;
int con[100005];
int DP[100005][2][2];

vector<int> v[100005];

void dfs(int p, int c){
    for(int i=0; i<2; i++){
        DP[c][i][con[c] ^ i] = i;
        DP[c][i][con[c] ^ i ^ 1] = n+1;
    }

    for(int u : v[c]){
        if(u != p){
            dfs(c, u);
            for(int i=0; i<2; i++){
                int off = DP[c][i][0], on = DP[c][i][1];
                DP[c][i][0] = min({n + 1, off + DP[u][0][i], on + DP[u][1][i]});
                DP[c][i][1] = min({n + 1, off + DP[u][1][i], on + DP[u][0][i]});
            }
        }
    }
}

int main()
{
    scanf("%d", &n);

    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0; i<n; i++) scanf("%d", &con[i]);

    dfs(-1, 0);

    int ans = min(DP[0][0][0], DP[0][1][0]);
    if(ans > n) printf("impossible");
    else printf("%d", ans);

    return 0;
}
