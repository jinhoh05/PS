#include <bits/stdc++.h>

using namespace std;

int n, m, year;
int ice[305][305], vt[305][305];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void melt(){
    int ice_berg[305][305];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ice_berg[i][j] = ice[i][j];
        }
    }

    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
             if(ice_berg[i][j]){
                 int cnt = 0;

                 for(int k=0;k<4;k++){
                      int x = i + dx[k];
                      int y = j + dy[k];
                      if(ice_berg[x][y] == 0) cnt++;
                 }

                 ice[i][j] = max(ice_berg[i][j] - cnt, 0);
             }
        }
    }
}

void dfs(int x,int y){
    vt[x][y] = 1;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(1 <= nx && nx < n - 1 && 1 <= ny && ny < m - 1){
            if(ice[nx][ny] && !vt[nx][ny]) dfs(nx, ny);
        }
    }
}

void iceberg(){
    while(1){
        memset(vt, 0, sizeof(vt));

        int cnt = 0;

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(ice[i][j] && vt[i][j] == 0){
                    cnt++;

                    if(cnt == 2){
                        cout << year;
                        return;
                    }

                    dfs(i,j);
                }
            }
        }

        if(cnt == 0){
            cout << "0";
            return;
        }

        melt();

        year++;
    }
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ice[i][j];
        }
    }

    iceberg();

    return 0;
}
