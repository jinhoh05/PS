#include <bits/stdc++.h>

using namespace std;
int n,m,k,c,ans,room_g[4],room_b[4],p,vt[1005][1005];

int main()
{
    scanf("%d %d",&k,&c);

    for(int i=1;i<=c;i++){
        scanf("%d %d",&n,&m);
        if(n<=m && m*2 > n+k+1) printf("0\n");
        else if(n>m && n*2 > m+k+2) printf("0\n");
        else printf("1\n");
    }

    return 0;
}