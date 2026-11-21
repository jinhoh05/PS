#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, m, ans = 1e9;
int v[55][55], vt[55];
vector<pii> house, chicken;

void dfs(int x, int chicken_cnt){
    if(chicken_cnt == m){
        int chicken_dist = 0;
        for(pii i : house){
            int d = 1e9, u = 0;
            for(pii j : chicken){
                int dist = abs(i.first - j.first) + abs(i.second - j.second);
                if(vt[u]) d = min(d, dist);
                u++;
            }
            chicken_dist += d;
        }
        ans = min(ans, chicken_dist);
        return;
    }

    if(x == chicken.size()) return;

    vt[x] = 1;
    dfs(x + 1, chicken_cnt + 1);

    vt[x] = 0;
    dfs(x + 1, chicken_cnt);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
            if(v[i][j] == 1) house.push_back({i, j});
            else if(v[i][j] == 2) chicken.push_back({i, j});
        }
    }

    dfs(0, 0);

    cout << ans;

    return 0;
}
