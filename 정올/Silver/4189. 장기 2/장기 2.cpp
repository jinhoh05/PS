#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Data{
    int x, y, cnt;
};

int n, m, ans;
int r, c, s, k;
int vt[1005][1005];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

vector<int> v;
queue<Data> q;

void push(int x, int y, int cnt)
{   
    if (x < 1 || x > n || y < 1 || y > m) return;
    if (vt[x][y]) return;   
    vt[x][y] = 1;
    
    q.push({x, y, cnt});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> r >> c >> s >> k;

    q.push({r, c, 0});
    vt[r][c] = 1;

    while (!q.empty())
    {
        auto [x, y, cnt] = q.front();
        q.pop();

        if (x == s && y == k) {
            cout << cnt;
            break;
        }

        for (int i = 0; i < 8; i++)
        {
            push(x + dx[i], y + dy[i], cnt + 1);
        }
    }
    
    return 0;
}

