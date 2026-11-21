#include <bits/stdc++.h>

using namespace std;

int n, m;
int maze[105][105], vt[105][105], ans[105][105];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

queue<pair<int, int>> que;

void push(int x, int y, int lev){
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(maze[x][y] == 0 || vt[x][y] == 1) return;

    ans[x][y] = lev;
    vt[x][y] = 1;
    que.push({x, y});

    return;
}

void bfs() {
    ans[1][1] = 1;
    vt[1][1] = 1;
    que.push({1, 1});

    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i=0;i<4;i++){
            push(x + dx[i], y + dy[i], ans[x][y] + 1);
        }
    }

    return;
}

int main() {

    scanf("%d %d",&n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d", &maze[i][j]);
        }
    }

    bfs();

    printf("%d", ans[n][m]);
    return 0;
}
