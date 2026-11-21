#include <bits/stdc++.h>
 
using namespace std;
int n,k,a,b,sum;
char code[1010][35];
int vt[1010];
int path[1010];
 
struct S{
    int x;
};
queue <S>que;
 
void check(int x){
    if(x == 0) return;
    check(path[x]);
    printf("%d ",x);
}
 
void push(int x,int y){
    if(vt[y])return;
    vt[y]=1;
    path[y]=x;
    que.push({y});
    if(y == b){
        check(b);
        sum=1;
        return;
    }
}
 
int haming(int x,int y){
    int cnt=0;
    for(int i=1;i<=k;i++){
        if(code[x][i] != code[y][i]) cnt++;
        if(cnt > 1) return 0;
    }
    if(cnt == 1) return 1;
    return 0;
}
 
int bfs(){
    S t;
    while(!que.empty()){
        t=que.front();
        que.pop();
        for(int i=1;i<=n;i++){
            if(haming(t.x,i)) push(t.x,i);
            if(sum) return 0;
        }
    }
    printf("-1");
    return 0;
}
 
int main()
{
    scanf("%d %d",&n,&k);
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            scanf(" %c",&code[i][j]);
        }
    }
 
    scanf("%d %d",&a,&b);
 
    vt[a]=1;
    que.push({a});
 
    bfs();
 
    /*printf("\n");
    for(int i=1;i<=n;i++){
        printf("%d ",path[i]);
    }*/
    return 0;
}