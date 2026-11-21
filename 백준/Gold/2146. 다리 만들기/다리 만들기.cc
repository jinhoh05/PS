#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n, ans = INF;
int island[105][105], vt[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int cnt){
    vt[x][y] = 1;
    island[x][y] = cnt;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < n && 0 <= ny && ny < n){
            if(island[nx][ny] && !vt[nx][ny]){
                dfs(nx, ny, cnt);
            }
        }
    }
}

int bfs(int cnt){
    queue<pair<int, int>> q;

    for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             if(island[i][j] == cnt){
                vt[i][j] = 1;
                q.push(make_pair(i, j));
             }
         }
    }

    int bridge = 0;

    while(!q.empty()){
        int Size = q.size();

        for(int i=0;i<Size;i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0 <= nx && nx < n && 0 <= ny && ny < n){
                    if(island[nx][ny] && island[nx][ny] != cnt) return bridge;

                    else if(!island[nx][ny] && !vt[nx][ny]){
                          vt[nx][ny] = 1;
                          q.push(make_pair(nx, ny));
                    }

                }
            }
        }
        bridge++;
    }

    return bridge;
}

void input(){
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> island[i][j];
        }
    }
}

int main()
{

    input();

    int cnt = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(island[i][j] && !vt[i][j]) dfs(i, j, cnt++);
        }
    }

    for(int i=1;i<cnt;i++){
        memset(vt, 0, sizeof(vt));
        ans = min(ans, bfs(i));
    }

    cout << ans << endl;

    return 0;

}
