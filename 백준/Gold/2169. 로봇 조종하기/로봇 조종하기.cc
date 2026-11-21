#include <bits/stdc++.h>

using namespace std;

const int INF = -987654321;

int n, m, ans;
int mars[1005][1005], vt[1005][1005];
int cost[1005][1005][3];

int dx[3] = {0, 0, 1};
int dy[3] = {1, -1, 0};

void input(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mars[i][j];
            cost[i][j][0] = cost[i][j][1] = cost[i][j][2] = INF;
        }
    }
}

int dfs(int x, int y, int d){
    if(x == n - 1 && y == m - 1) return mars[x][y];
    if(cost[x][y][d] != INF) return cost[x][y][d];

    vt[x][y] = 1;

    int val = INF;
    for(int i=0;i<3;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < n && ny < m && vt[nx][ny] == 0){
            val = max(val, dfs(nx, ny, i));
        }
    }

    vt[x][y] = 0;
    cost[x][y][d] = val + mars[x][y];

    return cost[x][y][d];
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();

    cout << dfs(0, 0, 0);

    return 0;
}
