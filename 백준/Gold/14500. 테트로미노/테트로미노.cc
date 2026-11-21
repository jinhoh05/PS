#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
int tetro[505][505], vt[505][505];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y, int cnt){
    if(cnt == 4) return tetro[x][y];

    int tetromino = 0;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < n && 0 <= ny && ny < m && !vt[nx][ny]){
            vt[nx][ny] = 1;
            tetromino = max(tetromino, tetro[x][y] + dfs(nx, ny, cnt + 1));
            vt[nx][ny] = 0;
        }
    }

    return tetromino;
}

int dfs2(int x, int y){
    int tetromino = 0;

    int x1 = x + 1, x2 = x - 1;
    int y1 = y + 1, y2 = y - 1;

    if(x >= 1 && y >= 1 && y < m - 1){
        tetromino = max(tetromino, tetro[x][y2] + tetro[x][y] + tetro[x2][y] + tetro[x][y1]);
    }

    if(x >= 1 && x < n - 1 && y < m - 1){
        tetromino = max(tetromino, tetro[x2][y] + tetro[x][y] + tetro[x][y1] + tetro[x1][y]);
    }

    if(x >= 0 && x < n - 1 && y < m - 1){
        tetromino = max(tetromino, tetro[x][y2] + tetro[x][y] + tetro[x1][y] + tetro[x][y1]);
    }

    if(x >= 1 && x < n - 1 && y >= 1){
        tetromino = max(tetromino, tetro[x2][y] + tetro[x][y] + tetro[x][y2] + tetro[x1][y]);
    }

    return tetromino;
}

void polyomino(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             vt[i][j] = 1;

             ans = max({ans, dfs(i, j, 1), dfs2(i, j)});

             vt[i][j] = 0;
        }
    }
}

void input(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> tetro[i][j];
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();

    polyomino();

    cout << ans;

    return 0;
}
