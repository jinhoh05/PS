#include <iostream>
#include <string.h>
using namespace std;

int m, n, k, t;
int organic[55][55], vt[50][50];
int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};

void dfs(int x, int y){
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        if(organic[nx][ny] && !vt[nx][ny]){
            vt[nx][ny]++;
            dfs(nx, ny);
        }
    }
}

int main(){

    scanf("%d", &t);

    for(int i=1;i<=t;i++){
        int x, y, ans = 0;

        scanf("%d %d %d", &m, &n, &k);
        swap(m, n);

        memset(organic, 0, sizeof(organic));
        memset(vt, 0, sizeof(vt));


        for(int i=1;i<=k;i++){
            scanf("%d %d", &x, &y);
            organic[x][y] = 1;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(organic[i][j] && !vt[i][j]){
                    ans++;
                    vt[i][j]++;
                    dfs(i, j);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
