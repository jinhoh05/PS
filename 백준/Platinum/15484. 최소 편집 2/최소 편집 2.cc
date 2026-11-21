#include <bits/stdc++.h>

using namespace std;

int da[26];
int dp[1005][1005];

string a, b;

int dynamic()
{
    int dist = a.size() + b.size();
    
    dp[0][0] = dist;
      
    for(int i = 1; i <= a.size() + 1; i++)
    {
        dp[i][0] = dist;
        dp[i][1] = i - 1;
    }
    
    for(int j = 1; j <= b.size() + 1; j++)
    {
        dp[0][j] = dist;
        dp[1][j] = j - 1;
    }
    
    fill_n(da, 26, 1);
    
    for(int i = 2; i < a.size() + 2; i++)
    {
        int db = 1; 
        
        for(int j = 2; j < b.size() + 2; j++)
        {
            int cost, k = da[b[j - 2] - 'a'], l = db; 
            
            if(a[i - 2] == b[j - 2])
            {
                cost = 0;
                db = j; 
            } 
            
            else cost = 1;
              
            dp[i][j] = min({dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + cost});
            dp[i][j] = min(dp[i][j], dp[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1));
        }
            
        da[a[i - 2] - 'a'] = i;
    }
    
    return dp[a.size() + 1][b.size() + 1];
}

int main() 
{
    cin >> a >> b;

    cout << dynamic();
    
    return 0;
}