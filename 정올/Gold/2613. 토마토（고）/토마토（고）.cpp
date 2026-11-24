#include <bits/stdc++.h>

using namespace std;
int n,m,mx;
int toma[1005][1005];
int used[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int tomato;
struct data{
    int x,y,lev;
};
queue <data>que;

void push(int x,int y,int lev){
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(used[x][y] || toma[x][y] || toma[x][y] == -1) return;
    used[x][y]=1;
    tomato--;
    que.push({x,y,lev});
}

int bfs(){
    data t;
    while(!que.empty()){
        t=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            push(t.x+dx[i],t.y+dy[i],t.lev+1);
        }
    }
    //printf("%d\n",t.lev);
    return t.lev;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d %d",&m,&n);
    tomato=m*n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&toma[i][j]);
            if(toma[i][j] == 1){
                que.push({i,j,1});
                used[i][j]=1;
            }
            if(toma[i][j] == -1 || toma[i][j]) tomato--;
        }
    }
    int mx;
    mx=bfs();

    if(tomato > 0) printf("-1");
    else printf("%d",mx-1);

    return 0;
}