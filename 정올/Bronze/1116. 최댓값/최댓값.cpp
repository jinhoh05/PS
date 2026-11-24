#include <bits/stdc++.h>

using namespace std;
int grid[10][10];
int ans,x,y;

int main()
{
    //freopen("input.txt","r",stdin);

    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            scanf("%d",&grid[i][j]);
            if(grid[i][j] > ans){
                x=i,y=j;
                ans=grid[i][j];
            }
        }
    }

    printf("%d\n%d %d",ans,x,y);

    return 0;
}