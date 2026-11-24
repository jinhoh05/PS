#include <bits/stdc++.h>

using namespace std;
char a[1005],b[1005];
int dp[1005][1005];
int n,m;
int px,py;
int score,t;
int cnt=1,sum=1;
int al,bl;

void track(int x,int y){

    if(dp[x][y] == 0){
        al=x;
        bl=y;
        return;
    }

    else if(a[x] == b[y]) track(x-1,y-1);

    else{
        if(dp[x][y] + 2 == dp[x-1][y]) track(x-1,y);
        else if(dp[x][y] + 2 == dp[x-1][y-1]) track(x-1,y-1);
        else track(x,y-1);
    }

}

int main()
{
    cin >> n >> a+1;
    cin >> m >> b+1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] == b[j]){
                dp[i][j]=dp[i-1][j-1]+3;
            }
            else{
                dp[i][j]=max({dp[i][j-1]-2,dp[i-1][j]-2,dp[i-1][j-1]-2,0});
            }

            if(score < dp[i][j]){
                score = dp[i][j];
                px = i;
                py = j;
            }
        }
    }

    printf("%d\n",score);

    track(px,py);


    for(int i=al+1;i<=px;i++){
        printf("%c",a[i]);
    }
    printf("\n");
    for(int i=bl+1;i<=py;i++){
        printf("%c",b[i]);
    }


    return 0;
}