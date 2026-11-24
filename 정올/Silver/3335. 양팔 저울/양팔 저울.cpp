#include <bits/stdc++.h>

using namespace std;
int n,m,cnt,hap;
int num[2000005],sinker[20];

void dfs(int lev,int w){
    num[w]=1;
    if(lev>=n) return;
    dfs(lev+1,w);
    dfs(lev+1,w+sinker[lev]);
    dfs(lev+1,abs(w-sinker[lev]));
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&sinker[i]);
        hap+=sinker[i];
    }

    dfs(0,0);
    for(int i=1;i<=hap;i++) cnt+=num[i];
    printf("%d",hap-cnt);

    return 0;
}