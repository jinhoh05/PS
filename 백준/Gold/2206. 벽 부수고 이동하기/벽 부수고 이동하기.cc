#include <bits/stdc++.h>

using namespace std;
int n, m;
int MAP[1005][1005], vt[1005][1005][2];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct st{
    int x, y, wall;
};
queue<st> q;

void push(int fx, int fy, int x, int y, int wall){
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(vt[x][y][wall]) return;

    if(MAP[x][y] == 0){
        vt[x][y][wall] = vt[fx][fy][wall] + 1;
        q.push({x, y, wall});
    }

    if(MAP[x][y] == 1 && wall == 0){
        vt[x][y][1] = vt[fx][fy][wall] + 1;
        wall = 1;
        q.push({x, y, wall});
    }
}

int bfs(){
    vt[1][1][0] = 1;
    q.push({1, 1, 0});

    while(!q.empty()){
        st t = q.front();
        q.pop();

        if(t.x == n && t.y == m) return vt[t.x][t.y][t.wall];

        for(int i=0;i<4;i++){
            push(t.x, t.    y, t.x + dx[i], t.y + dy[i], t.wall);
        }
    }

    return -1;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&MAP[i][j]);
        }
    }

    printf("%d", bfs());

    return 0;
}
