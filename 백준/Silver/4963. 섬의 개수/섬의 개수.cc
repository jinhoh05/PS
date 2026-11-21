#include <bits/stdc++.h>

using namespace std;

int w, h, cnt;
int island[55][55], vt[55][55];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void init(){
    cnt = 0;

    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            island[i][j] = vt[i][j] = 0;
        }
    }
}

void dfs(int x, int y) {
    if(vt[x][y]) return;
    vt[x][y] = 1;

    for(int i=0;i<8;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < h && ny >= 0 && ny < w){
            if(!vt[nx][ny] && island[nx][ny] == 1){
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

    while(1){
        init();

        cin >> w >> h;

        if(w == 0 && h == 0) break;

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> island[i][j];
            }
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!vt[i][j] && island[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
