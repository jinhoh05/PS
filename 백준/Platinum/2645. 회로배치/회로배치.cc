#include <bits/stdc++.h>
 
using namespace std;
int n,cnt;
int stx,sty,finx,finy;
int k,m;
int grid[55][55],vt[55][55],ans=5005;
int dx[5]={0,0,1,0,-1};
int dy[5]={0,-1,0,1,0};
int answer[55][3];
 
struct S{
    int x,y,lev;
    bool operator<(const S& t)const{
        return lev > t.lev;
    }
};
priority_queue <S>que;
 
void change(int x1,int y1,int x2,int y2){
    if(x1 == x2){
        if(y2 > y1) swap(y2,y1);
        for(int i=y2;i<=y1;i++) grid[x1][i]=1;
    }
    else{
        if(x2 > x1) swap(x2,x1);
        for(int i=x2;i<=x1;i++) grid[i][y1]=1;
    }
}
 
void push(int x,int y,int lev,int i){
    if(x < 1 || y < 1 || x > n || y > n) return;
    if(vt[x][y]) return;
    vt[x][y]=i;
    que.push({x,y,lev});
    if(x == finx && y == finy) if(lev < ans) ans=lev;
}
 
void bfs(int x,int y){
    int charge=1;
    if(grid[x][y]) charge=k;
    push(x,y,charge,-1);
    S t;
    while(!que.empty()){
        t=que.top();
        que.pop();
        for(int i=1;i<=4;i++){
            int charge=1;
            if(grid[t.x+dx[i]][t.y+dy[i]]) charge=k;
            push(t.x+dx[i],t.y+dy[i],t.lev+charge,i);
        }
    }
 
}
 
void look(int x,int y){
    if(vt[x][y]==-1) return;
 
    else if(vt[x][y] == 1){
        if(vt[x][y+1] != vt[x][y]){
            answer[++cnt][1]=x;
            answer[cnt][2]=y+1;
        }
        look(x,y+1);
    }
 
    else if(vt[x][y] == 2){
        if(vt[x-1][y] != vt[x][y]){
            answer[++cnt][1]=x-1;
            answer[cnt][2]=y;
        }
        look(x-1,y);
    }
 
    else if(vt[x][y] == 3){
        if(vt[x][y-1] != vt[x][y]){
            answer[++cnt][1]=x;
            answer[cnt][2]=y-1;
        }
        look(x,y-1);
    }
    else{
        if(vt[x+1][y] != vt[x][y]){
            answer[++cnt][1]=x+1;
            answer[cnt][2]=y;
        }
        look(x+1,y);
    }
}
 
int main()
{
    scanf("%d",&n);
    scanf("%d %d %d %d",&stx,&sty,&finx,&finy);
    scanf("%d %d",&k,&m);
 
    for(int i=1;i<=m;i++){
        int s,x1,x2,y1,y2;
        scanf("%d",&s);
        for(int j=1;j<=s;j++){
            scanf("%d %d",&x1,&y1);
            if(j > 1) change(x1,y1,x2,y2);
            x2=x1;
            y2=y1;
        }
    }
 
    bfs(stx,sty);
    look(finx,finy);
 
    printf("%d\n%d ",ans,cnt+1);
 
    for(int i=cnt;i>=1;i--){
        printf("%d %d ",answer[i][1],answer[i][2]);
    }
 
    printf("%d %d ",finx,finy);
 
    /*puts("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",vt[i][j]);
        }
        puts("\n");
    }*/
 
    return 0;
}