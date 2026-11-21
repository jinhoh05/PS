#include <bits/stdc++.h>
 
using namespace std;
 
int k,h,wall[25],line[25],used[25];
int cnt,mx=100000;
 
void dfs(int lev,int cnt,int n,int m){
    int ln = abs(line[lev]-n),lm = abs(m-line[lev]);
 
    if(lev > k){
        if(cnt < mx) mx=cnt;
        return;
    }
 
    if(n >= m) return;
 
    dfs(lev+1,cnt+ln,line[lev],m);
 
    dfs(lev+1,cnt+lm,n,line[lev]);
 
}
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    int n,m;
    scanf("%d %d %d %d",&h,&n,&m,&k);
 
    for(int i=1;i<=k;i++){
        scanf("%d",&line[i]);
    }
 
    dfs(1,0,n,m);
 
    printf("%d",mx);
    return 0;
}