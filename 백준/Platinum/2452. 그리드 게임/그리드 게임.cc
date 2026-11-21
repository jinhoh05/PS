#include <bits/stdc++.h>

using namespace std;
int n,m,cnt=2,check,greedy;
int color[105][105];
pair<int,int> greed[20005];
int vt[10005],visit[10005],visited[105][105];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector<int> com[10005];
int ans=1e9;

struct data{
    int x,y;
};

void dfs(int x,int y,int acolor,int bcolor){
    for(int i=0;i<4;i++){
        color[x][y] = bcolor;
        int X=x+dx[i],Y=y+dy[i];
        if(color[X][Y]==acolor) dfs(X,Y,acolor,bcolor);
    }
}

int push(int st){
    int counter=0;
    queue<int> que;
    vt[st]=1;
    que.push(st);
    while(!que.empty()){
        if(counter  >= ans) return ans;
        int sz=que.size();
        for(int i=0;i<sz;i++){
            int q=que.front();
            que.pop();
            for(int j=0;j<com[q].size();j++){
                if(vt[com[q][j]]==0){
                    vt[com[q][j]]=1;
                    que.push(com[q][j]);
                }
            }
        }
        counter++;
    }
    return counter-1;
}

void bfs(int x,int y){
    queue<data> que;
    que.push({x,y});
    while(!que.empty()){
        if(check >= cnt*3/5) return;
        data t=que.front();
        que.pop();
        if(t.x < 1 || t.y < 1 || t.x > n || t.y > m) continue;
        if(visit[color[t.x][t.y]]==0) {
            ans=push(color[t.x][t.y]);
            memset(vt,0,sizeof(vt));
            check++;
        }
        visit[color[t.x][t.y]]=1;
        for(int i=0;i<4;i++){
            int X=t.x+dx[i],Y=t.y+dy[i];
            if(visited[X][Y]==0){
                visited[X][Y]=1;
                que.push({X,Y});
            }
        }
    }

}

int main()
{
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

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(color[i][j] == 0 || color[i][j] == 1) dfs(i,j,color[i][j],cnt++);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            color[i][j]-=2;
        }
    }
    cnt-=2;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<2;k++){
                int x=i+dx[k],y=j+dy[k];
                if(color[x][y]==-1) continue;
                if(color[i][j] != color[x][y]){
                    if(color[i][j] > color[x][y]) greed[greedy++]={color[x][y],color[i][j]};
                    else greed[greedy++]={color[i][j],color[x][y]};
                }
            }
        }
    }
    sort(greed,greed+greedy);

    com[greed[0].first].push_back(greed[0].second);
    com[greed[0].second].push_back(greed[0].first);

    for(int i=1;i<greedy;i++){
        if(greed[i] != greed[i-1]){
            com[greed[i].first].push_back(greed[i].second);
            com[greed[i].second].push_back(greed[i].first);
        }
    }

    bfs(n/2,m/2);

    if(ans==1e9) printf("0");
    else printf("%d",ans);

    return 0;
}
