#include <bits/stdc++.h>
 
using namespace std;
int n,m,cnt,cheese,ans;
int chs[105][105],used[105][105];
 
 
void melt(int x,int y){
 
    if(x < 1 || y < 1 || x > n || y > m || used[x][y]) return;
    used[x][y]=1;
    if(chs[x][y]){
        chs[x][y]=0;
        cheese--;
        return;
    }
 
    melt(x-1,y);
    melt(x,y-1);
    melt(x+1,y);
    melt(x,y+1);
 
}
 
int main()
{
 
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    scanf("%d %d",&n,&m);
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&chs[i][j]);
            if(chs[i][j] == 1) cheese++;
        }
    }
 
    while(1){
        cnt=cheese;
        ans++;
        memset(used,0,sizeof(used));
        melt(1,1);
        if(cheese == 0) break;
    }
 
 
 
    printf("%d\n%d",ans,cnt);
    return 0;
}