#include <bits/stdc++.h>

using namespace std;
int n,m,a;
int s1,e1,s2,e2;
long long int hap[1005][1005];

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a);
            hap[i][j]=hap[i-1][j] + hap[i][j-1] - hap[i-1][j-1] + a;
        }
    }

    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d %d",&s1,&s2,&e1,&e2);
        printf("%lld\n",hap[e1][e2]+hap[s1-1][s2-1]-hap[s1-1][e2]-hap[e1][s2-1]);
    }

    return 0;
}