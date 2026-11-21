#include <iostream>
using namespace std;

int n, len, ans;
int DP[505][505], forest[505][505];

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

int dfs(int x, int y){
    if(DP[x][y]) return DP[x][y];
    DP[x][y]=1;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;

        if(forest[x][y] >= forest[nx][ny]) continue;

        DP[x][y] = max(DP[x][y], dfs(nx, ny) + 1);
    }

    return DP[x][y];
}
int main(){

    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&forest[i][j]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans = max(ans, dfs(i, j));
        }
    }

    printf("%d", ans);

    return 0;
}
