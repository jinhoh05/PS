#include <bits/stdc++.h>

using namespace std;

int n,m;
int r,c,s,k;
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int used[110][110];

struct data{
    int x,y,lev;
};
queue <data>que;

void push(int x,int y,int lev){
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(used[x][y]) return;
    used[x][y]=1;
    que.push({x,y,lev}) ;
}

int bfs(){
    push(r,c,0);
    data t;
    while(!que.empty()){
        t=que.front();
        que.pop();
        if(t.x==s && t.y==k)return t.lev;
        for(int i=0;i<8;i++){
            push(t.x+dx[i],t.y+dy[i],t.lev+1);
        }
    }
    return -1;
}

int main()
{

    scanf("%d %d",&n,&m);
    scanf("%d %d %d %d",&r,&c,&s,&k);

    printf("%d",bfs());

    return 0;
}