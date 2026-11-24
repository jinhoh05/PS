#include <bits/stdc++.h>

using namespace std;
int n,m;
int craft[110][110],used[110][110];
int x,y;
int jugle;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int mx;

struct data{
    int r,c,lev;
};
queue <data>que;

void push(int r,int c,int lev){
    if(r < 1 || r > n || c < 1 || c > m) return;
    if(used[r][c]!=0 || craft[r][c] == 0) return;
    used[r][c]=1;
    jugle--;
    que.push({r,c,lev});
}

int bfs(){
    push(x,y,3);
    data t;

    while(!que.empty()){
        t=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            push(t.r+dx[i],t.c+dy[i],t.lev+1);
        }

    }
    return t.lev;
}

int main()
{
    //freopen("input.txt","r",stdin);

    scanf("%d %d",&m,&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&craft[i][j]);
            if(craft[i][j] == 1) jugle++;
        }
    }

    scanf("%d %d",&y,&x);
    mx=bfs();
    printf("%d\n%d",mx,jugle);
    return 0;
}