#include<bits/stdc++.h>

#define LM 500+10
#define INF 999999999

using namespace std;
 
int arr[LM][LM];
int Gorge[LM][LM];
int R,C,N,ans=INF;
int dp[LM][LM][11];
 
void input()
{
    scanf("%d %d %d",&R,&C,&N);
    
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            scanf("%d",&arr[i][j]);
    
    for(int i=0;i<=503;i++)
        for(int j=0;j<=503;j++)
            for(int k=0;k<=10;k++)
                dp[i][j][k]=INF;
}
 
void gorge()
{
    for(int i = 2; i < R; i++)
    {
        for(int j = 2; j < C; j++)
        {
            int t = arr[i][j];
            
            if(arr[i - 1][j]> t && arr[i + 1][j] > t && arr[i][j - 1] < t&& arr[i][j + 1] < t && arr[i][j - 1] != -1 && arr[i][j + 1] != -1)
               Gorge[i][j] = 1;
        }
    }
}
 
void dynamic()
{
    for(int i = 1; i <= R; i++)
    {
        if(arr[i][1] != -1) dp[i][1][0] = arr[i][1];
    }
 
    for(int j = 2; j <= C; j++)
    {
        for(int i = 1; i <= R; i++)
        {
            for(int k = 0;k <= 10; k++)
            {
                if(arr[i][j] != -1 && k - Gorge[i][j] != -1)
                {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k - Gorge[i][j]] + arr[i][j]);
                    dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k - Gorge[i][j]] + arr[i][j]);
                    dp[i][j][k] = min(dp[i][j][k], dp[i + 1][j - 1][k - Gorge[i][j]] + arr[i][j]);
                }
            }
        }
    }
}
 
void output()
{
    for(int i = 1; i <= R; i++) ans = min(ans, dp[i][C][N]);
    
    if(ans == INF) printf("impossible");
    else printf("%d", ans);
}
 
int main()
{
    input();
    
    gorge();
    
    dynamic();
    
    output();
    
    return 0;
}