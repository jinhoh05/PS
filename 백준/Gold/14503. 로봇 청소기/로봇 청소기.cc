#include <cstdio>
using namespace std;

int n, m, cnt, r, c, d;
int robot[55][55];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int d) {
    if(robot[x][y] == 0){
        cnt++;
        robot[x][y] = 2;
    }

    for(int k=d-1;k>=d-4;k--) {
        int nk = (k + 4) % 4;
        int nx = x + dx[nk];
        int ny = y + dy[nk];

        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;

        if(robot[nx][ny] == 0) {
            dfs(nx, ny, nk);
            return;
        }
    }

    if(robot[x - dx[d]][y - dy[d]] == 1) return;
    else dfs(x - dx[d], y - dy[d], d);
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &robot[i][j]);
        }
    }

    dfs(r, c, d);

    printf("%d", cnt);

    return 0;
}
