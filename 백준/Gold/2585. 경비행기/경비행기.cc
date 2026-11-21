#include <bits/stdc++.h>
 
using namespace std;
int n,k,ans;
int low=1,mid,high=1415;
int vt[10010];
 
struct S{
    int x,y,lev;
}fly[10005];
queue <S>que;
 
int calc(int sx,int sy,int fx,int fy){
    int x=(fx-sx)*(fx-sx);
    int y=(fy-sy)*(fy-sy);
    return mid*mid*100 < x+y;
}
 
void push(int p,int c,int lev){
    if(vt[c] || lev > k) return;
    int num=calc(fly[p].x,fly[p].y,fly[c].x,fly[c].y);
    if(num) return;
    vt[c]=1;
    que.push({p,c,lev});
}
 
int bfs(){
    S t;
    memset(vt,0,sizeof(vt));
    while(!que.empty()) que.pop();
    push(0, 0, 0);
    while(!que.empty()){
        t=que.front();
        if(t.y==n) return 1;
        que.pop();
        for(int i=1;i<=n;i++){
            push(t.y,i,t.lev+1);
        }
    }
    return 0;
}
 
int main()
{
    scanf("%d %d",&n,&k);
    k++;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&fly[i].x,&fly[i].y);
    }
    fly[++n]={10000,10000};
 
    while(low <= high){
        mid=(low+high)/2;
        if(bfs()){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    printf("%d",ans);
 
    return 0;
}