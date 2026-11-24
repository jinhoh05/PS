#include <bits/stdc++.h>

using namespace std;
int n, m, h, ans;
int r[1005][1005], c[1005][1005], vt[1005][1005];

struct data{
    int x,y,lev;
    bool operator<(const data &t)const{
        return lev > t.lev;
    }
};
priority_queue<data> tank;

void push(int x, int y, int lev){
    if(vt[x][y]) return;
    tank.push({x, y, lev});
}

void input(){
    scanf("%d %d %d",&n,&m,&h);

    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&r[i][j]);
            if(r[i][j] == -1) r[i][j] = h;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m+1;j++){
            scanf("%d",&c[i][j]);
            if(c[i][j] == -1) c[i][j] = h;
        }
    }

    for(int i=1;i<=n;i++){
        push(i, 1, c[i][1]);
        push(i, m, c[i][m + 1]);
        vt[i][0] = vt[i][m + 1] = 1;
    }

    for(int i=1;i<=m;i++){
        push(1, i, r[1][i]);
        push(n, i, r[n + 1][i]);
        vt[0][i] = vt[n + 1][i] = 1;
    }
}

int water_tank(){
    int x, y, lev;
    data t;

    while(!tank.empty()){
        t=tank.top();
        tank.pop();
        x = t.x, y = t.y, lev = t.lev;
        if(vt[x][y]) continue;
        vt[x][y] = 1;
        ans += lev;
        push(x - 1, y, max(lev, r[x][y]));
        push(x + 1, y, max(lev, r[x + 1][y]));
        push(x, y - 1, max(lev, c[x][y]));
        push(x, y + 1, max(lev, c[x][y + 1]));
    }

    return ans;
}

int main()
{
    input();
    printf("%d", water_tank());

    return 0;
}