#include <bits/stdc++.h>
 
using namespace std;
char a[1005],b[1005];
int dp[1005][1005];
int n,m;
int px,py;
pair<int, int> fr[1001][1001];
int score,t;
int cnt=1;
int main()
{
    cin >> n >> a+1;
    cin >> m >> b+1;
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] == b[j]){
                dp[i][j]=3;
                fr[i][j]={i,j};
            }
            else dp[i][j]=-2;
 
            t = dp[i-1][j-1] + dp[i][j];
 
            if(dp[i][j] < t){
                dp[i][j] = t;
                fr[i][j] = fr[i - 1][j - 1];
            }
 
            if(dp[i][j] < dp[i-1][j]-2){
                dp[i][j] = dp[i-1][j]-2;
                fr[i][j] = fr[i - 1][j];
            }
 
            if(dp[i][j] < dp[i][j-1]-2){
                dp[i][j] = dp[i][j-1]-2;
                fr[i][j] = fr[i][j - 1];
            }
 
            if(score < dp[i][j]){
                score = dp[i][j];
                px = i;
                py = j;
            }
        }
    }
 
    a[px+1] = b[py+1] = 0;
 
    printf("%d\n",score);
 
    for(int i=fr[px][py].first;i<=px;i++){
        printf("%c",a[i]);
    }
    cout << "\n";
     
    for(int i=fr[px][py].second;i<=py;i++){
        printf("%c",b[i]);
    }
     
    return 0;
}