#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, cnt, val;

ll dp[5005][2];

struct node{

    ll x, y;

    bool operator<(const node& t)
    {
        return x < t.x;
    }
}; 

node s[5005], t[5005];

int calc()
{
    int x = 0, f = 1; 
    char s;
    
    while((s = getchar()) < '0' || s > '9') 
    {
        if(s == '-') f = -1;
    }
    
    while(s >= '0' && s <= '9')
    {
        x = (x << 1) + (x << 3) + (s ^ 48);
        s = getchar();
    }

    return x * f;
}

int main() 
{
    n = calc();
    
    for(int i = 1; i <= n; ++ i)
    {
        s[i].x = abs(calc());
        s[i].y = abs(calc());
    }
    
    sort(s + 1, s + n + 1);
    
    cnt++;
    
    val = t[cnt].y = s[n].y, t[cnt].x = s[n].x;
    
    for(int i = n - 1; i; i--)
    {
        if(s[i].y > val)
        {
            val = s[i].y;
            t[++cnt] = s[i];
        }
    }
    
    for(int i = cnt; i; i--) 
    {
        dp[i][1] = min(dp[i + 1][0], dp[i + 1][1]) + t[i].x * t[i].y;
        dp[i][0] = dp[i][1];
        
        for(int j = i + 1; j <= cnt; j++)
        {
            dp[i][0] = min(dp[i][0], dp[j][1] + t[j].y * (t[i].x - t[j].x));
        }
    }
    
    printf("%lld\n", min(dp[1][0], dp[1][1]) << 2);
    
    return 0;
}