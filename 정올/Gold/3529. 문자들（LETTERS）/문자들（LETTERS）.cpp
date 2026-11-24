#include <bits/stdc++.h>

using namespace std;
int cnt[201],r,c;
int big;
char a[25][25];
int vt[25][25];
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};

void dfs(int lev,int x,int y){
    if(x < 1 || y < 1 || x > r || y > c) return;
    if(vt[x][y] || cnt[a[x][y]]) return;

    if(lev > big) big=lev;

    vt[x][y]=1;
    cnt[a[x][y]]=1;

    dfs(lev+1,x,y+1);
    dfs(lev+1,x+1,y);
    dfs(lev+1,x,y-1);
    dfs(lev+1,x-1,y);

    vt[x][y]=0;
    cnt[a[x][y]]=0;
}

int main()
{
    scanf("%d %d",&r,&c);

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf(" %c",&a[i][j]);
        }
    }

    dfs(1,1,1);

    printf("%d",big);

    return 0;
}