#include <bits/stdc++.h>

using namespace std;
int n,m,ans=100;
char a[6][15];
int x[15];

int check(int i,int s,int e){
    for(int j=1;j<=m;j++){
        if(s <= j && j <= e){
            if(a[i][j] != '*') return 0;
        }
        else{
            if(x[j] == 1 && a[i][j] != '*') return 0;
            else if(x[j] == 0 && a[i][j] != '.') return 0;
        }
    }
    return 1;
}

void dfs_x(int cnt,int i){
    if(i > n){
        if(cnt < ans) ans=cnt;
        return;
    }

    int sm=0;

    if(check(i,0,0)){
        dfs_x(cnt,i+1);
        return;
    }

    int sum=0;

    for(int j=1;j<=m-4;j++){
        if(check(i,j,j+4)){
            dfs_x(cnt+1,i+1);
            return;
        }
    }

    for(int j=1;j<=m-5;j++){
        for(int k=j+5;k<=m;k++){
            if(check(i,j,k)){
                dfs_x(cnt+2,i+1);
                return;
            }
        }
    }
}

void fivestar(int lev,int cnt){
    if(lev > m){
        dfs_x(cnt,1);
        return;
    }

    x[lev]=0;
    fivestar(lev+1,cnt);
    x[lev]=1;
    fivestar(lev+1,cnt+1);
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
        }
    }

    if(n == 5) fivestar(1,0);
    else dfs_x(0,1);

    if(ans==100) ans=-1;
    printf("%d",ans);

    return 0;
}