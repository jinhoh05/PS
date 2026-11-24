#include <bits/stdc++.h>

using namespace std;
int n;
int dsx,dsy,dfx,dfy;
int ssx,ssy,sfx,sfy;
int vill[30][30];
int visit[30][30][30][30];
int dx[9]={0,0,1,1,1,0,-1,-1,-1};
int dy[9]={0,-1,-1,0,1,1,1,0,-1};

struct data{
    int x,y,x1,y1,lev;
};
queue<data>gosm;

int push(int x,int y,int x1,int y1,int lev){
    if(x < 1 || x > n || y < 1 || y > n) return 0;
    if(x1 < 1 || x1 > n || y1 < 1 || y1 > n) return 0;
    if(abs(x1-x) <= 1 && abs(y1-y) <= 1) return 0;
    if(vill[x][y] || vill[x1][y1]) return 0;
    if(visit[x][y][x1][y1]) return 0;
    visit[x][y][x1][y1]=1;
    gosm.push({x,y,x1,y1,lev});
    if(x==dfx && y==dfy && x1==sfx && y1==sfy) return 1;
    return 0;
}

int bfs(){

    while(!gosm.empty()){
        data t=gosm.front();
        gosm.pop();
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(push(t.x+dx[i],t.y+dy[i],t.x1+dx[j],t.y1+dy[j],t.lev+1)) return t.lev+1;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    scanf("%d %d %d %d",&dsx,&dsy,&dfx,&dfy);
    scanf("%d %d %d %d",&ssx,&ssy,&sfx,&sfy);
    visit[dsx][dsy][ssx][ssy]=1;
    gosm.push({dsx,dsy,ssx,ssy,0});

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&vill[i][j]);
        }
    }

    printf("%d",bfs());

    return 0;
}