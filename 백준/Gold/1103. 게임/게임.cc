#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;

int n, m;
int vt[55][55], DP[55][55], board[55][55];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m || !board[x][y]) return 0;

    if(vt[x][y]){
        cout << -1;
        exit(0);
    }

    if(DP[x][y]) return DP[x][y];

    vt[x][y] = 1;

    for(int i=0;i<4;i++){
        int val = dfs(x + board[x][y] * dx[i], y + board[x][y] * dy[i]) + 1;
        DP[x][y] = max(DP[x][y], val);
    }

    vt[x][y] = 0;
    return DP[x][y];
}

void input(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;

            if(c <= '9') board[i][j] = c - '0';
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();

    cout << dfs(0, 0);

    return 0;
}
