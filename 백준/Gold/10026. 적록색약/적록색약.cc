#include <bits/stdc++.h>

using namespace std;

int n, normal, n_normal;
bool vt[105][105];
char RGB[105][105];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y){
    vt[x][y] = 1;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 1 && nx <= 100 && ny >= 1 && ny <= 100){
            if(!(vt[nx][ny]) && (RGB[nx][ny] == RGB[x][y])){
                dfs(nx, ny);
            }
        }
    }
}

void finding(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vt[i][j]){
                dfs(i, j);
                normal++;
            }
        }
    }

    memset(vt, false, sizeof(vt));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(RGB[i][j] == 'R') RGB[i][j] = 'G';
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vt[i][j]){
                dfs(i, j);
                n_normal++;
            }
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> RGB[i][j];
        }
    }

    finding();

    cout << normal << " " << n_normal;

    return 0;
}
