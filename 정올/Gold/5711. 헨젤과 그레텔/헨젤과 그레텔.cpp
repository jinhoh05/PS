#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, a, b;
int block[105][105];

ll ans = 1;

vector<pii> v;

bool error()
{
    for (int i = 1; i < v.size(); i++) 
    {
        if (v[i - 1].second > v[i].second) {
            cout << 0 << '\n';
            return false;
        }
    }

    for (auto [x, y] : v) 
    {
        if (block[x][y]) 
        {
            cout << 0 << '\n';
            return false;
        }
    }

    return true;
}

void dynamic()
{
    for (int i = 1; i < v.size(); i++)
    {
        auto [sx, sy] = v[i - 1];
        auto [ex, ey] = v[i];

        ll dp[105][105] = {};
        dp[sx][sy] = 1;

        for (int x = sx; x <= ex; x++) 
        {
            for (int y = sy; y <= ey; y++) 
            {
                if (x == sx && y == sy) continue;

                if (block[x][y]) {
                    dp[x][y] = 0;
                    continue;
                }

                if (x > sx) dp[x][y] += dp[x - 1][y];
                if (y > sy) dp[x][y] += dp[x][y - 1];
            }
        }

        ans *= dp[ex][ey];

        if (ans == 0) return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> a >> b;
    
    v.push_back({1, 1});

    for (int i = 0; i < a; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i = 0; i < b; i++)
    {
        int x, y;
        cin >> x >> y;
        block[x][y] = 1;
    }

    v.push_back({n, m});

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    if (!error()) return 0;

    dynamic();

    cout << ans;

    return 0;
}