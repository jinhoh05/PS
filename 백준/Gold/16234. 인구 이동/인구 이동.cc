#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, l, r;
int p, ans, num;
int world[55][55], vt[55][55];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<pii> v;

void dfs(int x, int  y){
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        int d = abs(world[x][y] - world[nx][ny]);

        if(0 <= nx && nx < n && 0 <= ny && ny < n){
            if(l <= d && d <=r && !vt[nx][ny]){
                vt[nx][ny] = 1;
                v.push_back({nx, ny});
                p += world[nx][ny];
                num++;
                dfs(nx, ny);
            }
        }
    }
}

bool push(){
    bool flag = false;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vt[i][j]) continue;

            vt[i][j] = 1;
            p = world[i][j];
            num = 1;

            v.clear();
            v.push_back({i, j});
            dfs(i, j);

            if(num >= 2){
                flag = true;
                for(pii u : v) world[u.first][u.second] = p / num;
            }
        }
    }

    return flag;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> l >> r;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> world[i][j];
        }
    }

    while(1){
        memset(vt, 0, sizeof(vt));

        bool flag = push();

        if(flag) ans++;
        else break;
    }

    cout << ans;

    return 0;
}
