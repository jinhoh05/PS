#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, ans, cnt;
int shark_x, shark_y, shark = 2;
int min_x, min_y, d;
int water[25][25], vt[25][25];
queue<pii> q;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void init(){
    while(!q.empty()) q.pop();
    min_x = min_y = 21;
    d = 401;
    memset(vt, -1, sizeof(vt));
}

void check(int x, int y){
    int k = 0, kd = 0;

    if(water[x][y] != 0 && water[x][y] < shark){
        if(d > vt[x][y]) k = kd = 1;

        else if(d == vt[x][y]){
            if(min_x == x && min_y > y) k = 1;

            else if(min_x > x) k = 1;
        }
    }

    if(k){
        min_x = x;
        min_y = y;
    }

    if(kd) d = vt[x][y];
}

void push(int val, int x, int y){
    if(x < 1 || x > n || y < 1 || y > n) return;
    if(vt[x][y] != -1 || water[x][y] > shark) return;

    vt[x][y] = val;

    check(x, y);

    q.push({x, y});
}

void bfs(int x, int y){
    vt[x][y] = 0;
    q.push({x, y});

    while(!q.empty()){
        pii t = q.front();
        q.pop();

        int x = t.first, y = t.second;

        for(int i=0;i<4;i++) push(vt[x][y] + 1, x + dx[i], y + dy[i]);
    }
}

void fish(){
    while(1){
        init();

        bfs(shark_x, shark_y);

        if(min_x != 21 && min_y != 21){
            ans += vt[min_x][min_y];
            cnt++;

            if(cnt == shark){
                shark++;
                cnt = 0;
            }

            water[min_x][min_y] = 0;

            shark_x = min_x;
            shark_y = min_y;
        }

        else return;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> water[i][j];
            if(water[i][j] == 9){
                shark_x = i;
                shark_y = j;
                water[i][j] = 0;
            }
        }
    }

    fish();

    cout << ans;

    return 0;
}
