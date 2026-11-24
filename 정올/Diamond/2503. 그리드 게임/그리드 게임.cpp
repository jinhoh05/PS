#include <bits/stdc++.h>

using namespace std;
int n,m,cnt=2,greedy;
int color[105][105];
set <int> greed[10005];
int vt[10005],bound[10005];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector<int> com[10005];
int ans=1e9;
queue<pair<int,int>> que;

void dfs(int x,int y,int acolor,int bcolor){
    for(int i=0;i<4;i++){
        color[x][y] = bcolor;
        int X=x+dx[i],Y=y+dy[i];
        if(color[X][Y]==acolor) dfs(X,Y,acolor,bcolor);
    }
}


void push(int x,int lev){
    if(vt[x]) return;
    vt[x]=lev+1;
    que.push({x,lev});
}

int bfs(int x){
    memset(vt,0,sizeof(vt));
    int lev;
    push(x,0);
    while(!que.empty()){
        int px=que.front().first;
        lev=que.front().second;
        que.pop();
        for(int i:greed[px]){
            push(i,lev+1);
        }
    }
    for(int i=1;i<=cnt;i++){
        vt[i]--;
        bound[i]=max({bound[i],vt[i], lev-vt[i]});
    }
    return lev;
}

void input(){
    scanf("%d %d",&n,&m);

    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            color[i][j]=-1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&color[i][j]);
        }
    }
}

void graph(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(color[i][j] == 0 || color[i][j] == 1) dfs(i,j,color[i][j],cnt++);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            color[i][j]-=1;
        }
    }
    cnt-=2;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<2;k++){
                int x=i+dx[k],y=j+dy[k];
                if(color[x][y]==-1) continue;
                if(color[i][j] != color[x][y]){
                    greed[color[x][y]].insert(color[i][j]);
                    greed[color[i][j]].insert(color[x][y]);
                }
            }
        }
    }

}

int main()
{

    input();
    graph();


    for(int i=1;i<=cnt;i++){
        if(bound[i] >= ans) continue;
        int lev=bfs(i);
        ans=min(ans,lev);
    }

    printf("%d",ans);

    return 0;
}