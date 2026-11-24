#include <bits/stdc++.h>

using namespace std;
string s;
int dp[40];

int main()
{

    cin >> s;
    dp[0]=dp[1]=1;

    for(int i=1;i<s.size();i++){
       if(s[i]-48 == 0){
            if((s[i-1]-48)*10 + (s[i]-48) > 34){
                printf("0");
                return 0;
            }
       }
       else if((s[i-1]-48)*10 + (s[i]-48) <= 34){
            dp[i+1]=dp[i]+dp[i-1];
       }
       else{
            dp[i+1]=dp[i];
       }
    }
    printf("%d",dp[s.size()]);


    return 0;
}