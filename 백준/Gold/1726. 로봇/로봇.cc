#include<bits/stdc++.h>
 
using namespace std;
 
int n,m;
int vt[105][105][5];
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
 
int robot[105][105];
int fx,fy,fz;
int sx,sy,sz;
 
struct S{
    int x,y,z,lev;
};
 
queue <S>que;
 
int push(int x,int y,int z,int lev){
 
    if(vt[x][y][z]) return 0;
    if(robot[x][y]==0) return -1;
    vt[x][y][z] = 1;
    que.push({x,y,z,lev});
    return 0;
}
 
int bfs(){
    push(fx,fy,fz,0);
 
    S t;
 
    while(!que.empty()){
        t=que.front();
        if(t.x == sx && t.y == sy && t.z == sz) return t.lev;
        que.pop();
        for(int i=1;i<=3;i++){
            if(push(t.x+dx[t.z]*i,t.y+dy[t.z]*i,t.z,t.lev+1) < 0) break;
        }
 
        if(t.z < 3){
            push(t.x,t.y,3,t.lev+1);
            push(t.x,t.y,4,t.lev+1);
        }
        else{
            push(t.x,t.y,1,t.lev+1);
            push(t.x,t.y,2,t.lev+1);
        }
    }
 
    return 0;
}
 
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&robot[i][j]);
            robot[i][j] = !robot[i][j];
        }
    }
 
    scanf("%d %d %d",&fx,&fy,&fz);
    scanf("%d %d %d",&sx,&sy,&sz);
    printf("%d",bfs());
 
    return 0;
}