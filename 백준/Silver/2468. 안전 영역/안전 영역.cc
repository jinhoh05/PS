#include <bits/stdc++.h>

using namespace std;

int n;
int area[105][105], water[105][105], vt[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init(int h){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(area[i][j] > h) water[i][j] = area[i][j];
        }
    }
}

void dfs(int x, int y){
    vt[x][y] = 1;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < n && 0 <= ny && ny < n){
            if(!vt[nx][ny] && water[nx][ny]){
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> area[i][j];
        }
    }

    int h = 1;

    for(int k=1;k<=100;k++){
        memset(vt, 0, sizeof(vt));
        memset(water, 0, sizeof(water));

        init(k);

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vt[i][j] && water[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        h = max(h, cnt);
    }

    cout << h;

    return 0;
}
