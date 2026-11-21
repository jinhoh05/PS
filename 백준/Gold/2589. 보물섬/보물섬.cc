#include <bits/stdc++.h>
 
using namespace std;
int n,m,mx;
char trs[55][55];
int used[55][55];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
 
struct S{
    int x,y,lev;
};
queue <S>que;
 
void push(int x,int y,int lev){
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(used[x][y] || trs[x][y] == 'W') return;
    used[x][y]=1;
    que.push({x,y,lev});
}
 
int bfs(int x,int y){
    push(x,y,0);
    S t;
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
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&trs[i][j]);
        }
    }
    int big;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(trs[i][j] == 'L'){
                big=bfs(i,j);
                if(mx < big) mx=big;
                memset(used,0,sizeof(used));
            }
        }
    }
 
    printf("%d",mx);
    return 0;
}