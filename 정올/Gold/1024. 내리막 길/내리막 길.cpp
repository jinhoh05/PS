#include <bits/stdc++.h>
 
using namespace std;
int n,m,DP[505][505],Map[505][505],vt[505][505];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int cnt,ans;
 
int dynamic(int x,int y,int h){
    if(Map[x][y] <= h) return 0;
    
    if(vt[x][y] == 0) {
        vt[x][y]=1;
        for(int i=0;i<4;i++){
            DP[x][y]+=dynamic(x+dx[i],y+dy[i],Map[x][y]);
        }
    }
    
    return DP[x][y];
}
 
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&Map[i][j]);
        }
    }
    
    DP[1][1]=vt[1][1]=1;
    printf("%d",dynamic(n,m,0));
 
    return 0;
}