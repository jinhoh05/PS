#include <bits/stdc++.h>

using namespace std;
int n,m;
int dp[105][10005];
int hap;

struct data{

    int mi,ci;

}mmo[105];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
        scanf("%d",&mmo[i].mi);
    }

    for(int i=1;i<=n;i++){
        scanf("%d",&mmo[i].ci);
        hap+=mmo[i].ci;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=hap;j++){
            if(j-mmo[i].ci < 0) dp[i][j]+=dp[i-1][j];
            else dp[i][j]+=max(dp[i-1][j],dp[i-1][j-mmo[i].ci]+mmo[i].mi);
        }
    }


   /* for(int i=1;i<=n;i++){
        for(int j=0;j<=hap;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
*/
    for(int i=0;i<=hap;i++){
        if(dp[n][i] >= m){
            printf("%d",i);
            return 0;
        }
    }

    return 0;
}