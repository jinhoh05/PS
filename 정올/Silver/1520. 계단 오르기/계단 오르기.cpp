#include <bits/stdc++.h>

using namespace std;
int n;
int stair[305];
int dp[305];
int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&stair[i]);
    }
    dp[1]=stair[1];
    dp[2]=stair[2]+stair[1];

    int a,b;
    for(int i=3;i<=n;i++){
        a=stair[i]+dp[i-2];
        b=stair[i]+stair[i-1]+dp[i-3];
        dp[i]=max(a,b);
    }

    printf("%d",dp[n]);

    return 0;
}