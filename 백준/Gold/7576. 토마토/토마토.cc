#include <bits/stdc++.h>

using namespace std;

int n, m, ans, t_cnt;
int tomato[1005][1005], vt[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct st{
    int x, y, lev;
};

queue<st> q;

void push(int x, int y, int lev){
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(vt[x][y] || tomato[x][y] || tomato[x][y] == -1) return;

    vt[x][y] = 1;
    t_cnt--;
    q.push({x, y, lev});
}

int bfs(){
    st t;

    while(!q.empty()){
        t = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            push(t.x + dx[i], t.y + dy[i], t.lev + 1);
        }
    }

    return t.lev;
}

void find_tomato(){
    t_cnt = m * n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> tomato[i][j];

            if(tomato[i][j] == 1){
                q.push({i, j, 1});
                vt[i][j] = 1;
            }

            if(tomato[i][j] == -1 || tomato[i][j]) t_cnt--;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;

    find_tomato();

    ans = bfs();

    if(t_cnt > 0) cout << -1;
    else cout << ans - 1;

    return 0;
}
