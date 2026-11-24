#include <bits/stdc++.h>

using namespace std;
string a,b;
int dp[1005][1005];
int n,m;
int len1,len2;

void q(){
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }
}

int main()
{

    cin >> n >> a;
    cin >> m >> b;

    a = '0' + a;
    b = '0' + b;

    q();

    int cnt;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] == b[j]) cnt=0;
            else cnt=1;
            dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j]+1);
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+cnt);
        }
    }

    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            printf("%2d ",dp[i][j]);
        }
        printf("\n");
    }*/

    printf("%d",dp[n][m]);

    return 0;
}