#include <bits/stdc++.h>

using namespace std;
int n, m, k, s, e, w, cnt, pn;
int arr[30005], vt[30005], DP[2][3005];
vector<int> v[30005];
struct st{
    int child, candy;
}p[30005];

void dfs(int x) {
    vt[x] = 1;
    w += arr[x];
    cnt += 1;

    for(int u : v[x]){
        if(vt[u]) continue;
        dfs(u);
    }
}

void make_group(){
    for(int i=1;i<=n;i++){
        if(!vt[i]){
            w = 0;
            cnt = 0;
            dfs(i);
            p[++pn] = {cnt, w};
        }
    }
}

void dynamic(){
    for(int i=1;i<=pn;i++){
        int ci = p[i].child, w = p[i].candy;

        for(int j=0;j<k;j++) {
            if(j >= ci){
                DP[1][j] = max(DP[0][j], DP[0][j - ci] + w);
            }

            else DP[1][j] = DP[0][j];
        }

        for(int j=0;j<k;j++) DP[0][j] = DP[1][j];
    }
}

void input(){
    scanf("%d %d %d", &n, &m, &k);

    for(int i=1;i<=n;++i) scanf("%d", &arr[i]);

    for(int i=1;i<=m;i++){
        scanf("%d %d", &s, &e);
        v[s].push_back(e);
        v[e].push_back(s);
    }
}

int main()
{
    input();

    make_group();

    dynamic();

    printf("%d", DP[1][k - 1]);

    return 0;
}
