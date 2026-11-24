#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Data{
    int x, y, d;

    bool operator<(const Data &t)const{
        return d > t.d;
    }
};

int n, m, ans;
int room[55][55], vt[55][55];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

vector<int> v;
priority_queue<Data> pq;

void push(int x, int y, int d)
{
    if (x < 1 || x > n || y < 1 || y > n) return;
    if (vt[x][y]) return;
    pq.push({x, y, d});
}

int bfs()
{
    int k = abs(room[1][1] - 1);
    pq.push({1, 1, k});

    while (!pq.empty())
    {
        auto [x, y, d] = pq.top();
        pq.pop();

        if (vt[x][y]) continue;
        vt[x][y] = 1;

        if (x == n && y == n) return d;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            int nd = room[nx][ny] ? d : d + 1;
            push(nx, ny, nd);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            room[i][j] = s[j - 1] - '0';
        }
    }

    cout << bfs();

    return 0;
}