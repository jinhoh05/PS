#include <bits/stdc++.h>

using namespace std;
int n,m,mount[705][705],ans;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int vt[705][705];
struct Data{
    int x,y,high;
    bool operator<(const Data&t)const{
        return high>t.high;
    }
};
priority_queue<Data> que;

void push(int x,int y,int high){
    if(high < mount[x][y]) high=mount[x][y];
    if(x<1||x>n||y<1||y>m) return;
    if(high >= ans) return;
    if(vt[x][y]) return;
    vt[x][y]=1;
    if(x==n&&y==m){
        ans=high;
        return;
    }
    que.push({x,y,high});
}

void bfs(){
    while(!que.empty()){
        Data t=que.top();
        que.pop();
        for(int i=0;i<4;i++){
            push(t.x+dx[i],t.y+dy[i],t.high);
            if(t.x+dx[i]==n && t.y+dy[i]==m) return;
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mount[i][j]);
            ans=max(ans,mount[i][j]);
        }
    }

    if(ans==mount[1][1]){
        printf("%d",ans);
        return 0;
    }

    vt[1][1]=mount[1][1];
    que.push({1,1,mount[1][1]});
    bfs();
    printf("%d",ans);

    return 0;
}