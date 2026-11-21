#include <bits/stdc++.h>

using namespace std;
using pic = pair<int, char>;

int n, m, k, ans;
int DP[1005][505];

char s[1005];

vector<pic> v[505];

int dfs(int x, int lev){
    if(lev == n) return 0;

    int &ret = DP[lev][x];

    if(ret != -1) return ret;

    for(pic u : v[x]){
        int idx = u.first, color = u.second;

        ret = max(ret, dfs(idx, lev + 1) + (color == s[lev] ? 10 : 0));
    }

    return ret;
}

void input(){
    scanf("%d", &n);

    for(int i=0;i<n;i++) scanf(" %c", &s[i]);

    scanf("%d %d", &m, &k);

    for(int i=1;i<=k;i++){
        int a, b;
        scanf("%d %d", &a, &b);

        char c;
        scanf(" %c", &c);

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

int main()
{
    memset(DP, -1, sizeof(DP));

    input();

    ans = dfs(1, 0);

    printf("%d", ans != -1 ? ans : 0);

    return 0;
}
