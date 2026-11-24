#include <bits/stdc++.h>

using namespace std;
string a,b;
int dp[1005][1005];

int main()
{

    cin >> a >> b;

    a = '0' + a;
    b = '0' + b;

    for(int i=1;i<a.size();i++){
        for(int j=1;j<b.size();j++){
            if(a[i] == b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    printf("%d",dp[a.size()-1][b.size()-1]);

    return 0;
}