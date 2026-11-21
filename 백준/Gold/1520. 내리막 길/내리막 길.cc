#include<bits/stdc++.h>

using namespace std;

int n, m;
int way[505][505], DP[505][505];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dynamic(int x, int y){
    if(DP[x][y] != -1) return DP[x][y];
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(x == 0 && y == 0) return 1;

    DP[x][y] = 0;

    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(way[nx][ny] > way[x][y]) DP[x][y] += dynamic(nx, ny);
    }

    return DP[x][y];
}

int main(){

    scanf("%d %d", &n ,&m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &way[i][j]);
        }
    }

    memset(DP, -1, sizeof(DP));

    printf("%d", dynamic(n - 1, m - 1));

    return 0;
}
