#include <bits/stdc++.h>

using namespace std;
int n,cnt,mx,line[205],dp[205];

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&line[i]);
        dp[i]=1;
    }


    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            if(line[i] < line[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(dp[i] > mx) mx=dp[i];
    }

    printf("%d",n-mx);

    return 0;
}