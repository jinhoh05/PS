#include <bits/stdc++.h>

using namespace std;
int n,m,h,mx;
int toma[105][105][105];
int used[105][105][105];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int cnt;

struct data{
    int x,y,z,lev;
};
queue <data>que;

void output(){
    for(int k=1;k<=h;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(used[k][i][j] == 1) printf("%d %d %d\n",k,i,j);
            }
        }
    }

}

void push(int x,int y,int z,int lev){
    if(x < 1 || x > n || y < 1 || y > m || z < 1 || z > h) return;
    if(used[z][x][y] || toma[z][x][y] == -1) return;

    used[z][x][y]=1;
    //output();
    cnt--;
    que.push({x,y,z,lev});
}

int bfs(){
    data t;
    while(!que.empty()){
        t=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            push(t.x+dx[i],t.y+dy[i],t.z,t.lev+1);
        }
        push(t.x,t.y,t.z+1,t.lev+1);
        push(t.x,t.y,t.z-1,t.lev+1);
    }

    return t.lev;
}

int main()
{
    scanf("%d %d %d",&m,&n,&h);
    cnt=m*n*h;
    for(int k=1;k<=h;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&toma[k][i][j]);
                if(toma[k][i][j] == 1){
                    que.push({i,j,k,1});
                    used[k][i][j]=1;
                }
                if(toma[k][i][j] == -1 || toma[k][i][j]) cnt--;
            }
        }
    }

    int mx=bfs();

    if(cnt > 0) printf("-1");
    else printf("%d",mx-1);

    return 0;
}