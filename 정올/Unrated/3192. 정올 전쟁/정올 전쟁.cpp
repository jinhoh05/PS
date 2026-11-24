#include <bits/stdc++.h>

using namespace std;

int n,d=1000000007,vt[100005];
vector<vector<long>> k,dp;

void dfs(int x){
    vt[x]=1;
    long s=1,us=1;

    for(auto v:k[x]){
        if(vt[v]) continue;
        dfs(v);
        us*=dp[v][0],us%=d;
        s*=dp[v][0]+dp[v][0]+dp[v][1],s%=d;
    }

    s-=us,s+=d,s%=d;
    dp[x][0]=s;
    dp[x][1]=us;
}

int divide(int n, vector<vector<int>> ter) {
    for(auto v:ter){
        v[0]--,v[1]--;
        k[v[0]].push_back(v[1]);
        k[v[1]].push_back(v[0]);
    }

    dfs(0);
    return (2*dp[0][0])%d;
}

int main()
{
    scanf("%d",&n);

    vector<vector<int>> ter(n-1);
    k.resize(n);
    dp.resize(n,vector<long>(2));

    for(int i=0;i<n-1;i++){
        ter[i].resize(2);
        for(int j=0;j<2;j++){
            scanf("%d",&ter[i][j]);
        }
    }

    printf("%d",divide(n,ter));

    return 0;
}