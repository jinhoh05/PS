#include <bits/stdc++.h>

using namespace std;
int n,m,k,c,ans,p,vt[1005][1005],nec_x,nec_y;

int dfs(int x,int y){
    int grid[25][25];
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            grid[i][j]=0;
        }
    }
    grid[1][1]=1;

    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            grid[i][j+1]+=grid[i][j];
            grid[i+1][j]+=grid[i][j];
        }
    }
    return grid[x][y];
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);

    if(k==0) printf("%d",dfs(n,m));
    else{
        int x=(k-1)/m+1;
        int y=(k-1)%m+1;
        printf("%d",dfs(x,y)*dfs(n-x+1,m-y+1));
    }

    return 0;
}