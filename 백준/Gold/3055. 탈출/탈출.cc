#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, m;
int st_x, st_y;
int end_x, end_y;

int day[55][55], vt[55][55];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

char a[55][55];

queue<pii> q, pq;

void push(int val, int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m){
        if(day[x][y] == 0 && a[x][y] == '.'){
            day[x][y] = val + 1;
            q.push({x, y});
        }
    }
}

void water_bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();


        for(int i=0;i<4;i++) push(day[x][y], x + dx[i], y + dy[i]);
    }
}

void s_push(int val, int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m){
        if(vt[x][y] == 0 && (a[x][y] == '.' || a[x][y] == 'D')){
            if(day[x][y] == 0){
                vt[x][y] = val + 1;
                pq.push({x, y});
            }

            else{
                if(day[x][y] > val + 1){
                    vt[x][y] = val + 1;
                    pq.push({x, y});
                }
            }
        }
    }
}

void bfs(){
    pq.push({st_x, st_y});

    while(!pq.empty()){
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop();


        for(int i=0;i<4;i++) s_push(vt[x][y], x + dx[i], y + dy[i]);
    }
}

void check(int i, int j){
    if(a[i][j] == 'S'){
        st_x = i;
        st_y = j;
    }

    else if(a[i][j] == 'D'){
        end_x = i;
        end_y = j;
    }

    else if(a[i][j] == '*') q.push({i, j});
}

void input(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> a[i];

        for(int j=0;j<m;j++) check(i, j);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();

    water_bfs();

    bfs();

    if(vt[end_x][end_y]) cout << vt[end_x][end_y];
    else cout << "KAKTUS";

    return 0;
}
