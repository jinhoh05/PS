#include <bits/stdc++.h>
 
using namespace std;
 
int n,m,k,cnt,ct;
int squ[105][105], used[105][105];
int ans[10000];
 
void change(int lx,int ly,int rx,int ry){
    for(int i=ly+1;i<=ry;i++){
        for(int j=lx+1;j<=rx;j++){
            squ[i][j]=1;
        }
    }
 
    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",squ[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
}
 
void flood_fill(int x,int y){
 
    if(x < 1 || y < 1 || x > n || y > m) return;
    if(squ[x][y] || used[x][y]) return;
 
    used[x][y] = 1;
    ans[cnt]++;
 
    flood_fill(x-1,y);
    flood_fill(x,y-1);
    flood_fill(x+1,y);
    flood_fill(x,y+1);
}
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
 
    scanf("%d %d %d",&n,&m,&k);
 
    int lx,ly,rx,ry;
 
    for(int i=0;i<k;i++){
        scanf("%d %d %d %d",&lx,&ly,&rx,&ry);
        change(lx,ly,rx,ry);
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(squ[i][j] == 0 && used[i][j] == 0){
                cnt++;
                flood_fill(i,j);
            }
        }
    }
 
    printf("%d\n",cnt);
    sort(ans+1,ans+1+cnt);
    for(int i=1;i<=cnt;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
