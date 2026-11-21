#include<bits/stdc++.h>
 
using namespace std;
 
int n,m,sum;
int bus[100005][5];
int sx,sy,dx,dy;
int k,b;
int used[100005];
int X1,Y1,X2,Y2;
 
struct S{
    int b,lev;
};
 
queue <S>que;
 
int push(int a,int b,int lev){
 
    if(used[b]) return 0;
    if(bus[a][1] > bus[b][3] || bus[b][1] > bus[a][3]) return 0;
    if(bus[a][2] > bus[b][4] || bus[b][2] > bus[a][4]) return 0;
 
    used[b]=1;
    if(b == k+1){
        printf("%d",lev-1);
        return 1;
    }
    que.push({b,lev});
    return 0;
}
 
 
int bfs(){
    S t;
    while(!que.empty()){
        t=que.front();
        que.pop();
        for(int i=1;i<=k+1;i++){
            if(push(t.b,i,t.lev+1))return 0;
        }
    }
 
}
 
int main(){
    int tmp;
    scanf("%d %d %d",&m,&n,&k);
 
    for(int i=1;i<=k;i++){
        scanf("%d",&b);
        scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
        if(X1 > X2) swap(X1,X2);
        if(Y1 > Y2) swap(Y1,Y2);
        bus[i][1]=X1;
        bus[i][2]=Y1;
        bus[i][3]=X2;
        bus[i][4]=Y2;
    }
    scanf("%d %d %d %d",&sx,&sy,&dx,&dy);
 
    bus[0][1]=sx;
    bus[0][2]=sy;
    bus[0][3]=sx;
    bus[0][4]=sy;
 
    bus[k+1][1]=dx;
    bus[k+1][2]=dy;
    bus[k+1][3]=dx;
    bus[k+1][4]=dy;
 
 
    que.push({0,0});
 
    bfs();
 
    return 0;
}