#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5005;

int n, cnt, maxx;

ll dp[N][2];

struct node{

    ll x, y;

}; 

node s[N], t[N];

int read()
{
    int x = 0, f = 1; char s;
    while((s = getchar()) < '0' || s > '9') if(s == '-') f = -1;
    while(s >= '0' && s <= '9') {x = (x << 1) + (x << 3) + (s ^ 48); s = getchar();}
    return x * f;
}

bool cmp(const node a, const node b) {return a.x < b.x;}

int main() 
{
    n = read();
    
    for(int i = 1; i <= n; ++ i) s[i].x = abs(read()), s[i].y = abs(read());
    
    sort(s + 1, s + n + 1, cmp); ++ cnt;
    
    maxx = t[cnt].y = s[n].y, t[cnt].x = s[n].x;
    
    for(int i = n - 1; i; --i)
    {
        if(s[i].y > maxx)
        {
            maxx = s[i].y;
            t[++ cnt] = s[i];
        }
    }
    for(int i = cnt; i; --i) 
    {
        dp[i][1] = min(dp[i + 1][0], dp[i + 1][1]) + t[i].x * t[i].y;
        dp[i][0] = dp[i][1];
        for(int j = i + 1; j <= cnt; ++ j) dp[i][0] = min(dp[i][0], dp[j][1] + t[j].y * (t[i].x - t[j].x));
    }
    
    printf("%lld\n", min(dp[1][0], dp[1][1]) << 2);
    
    return 0;
}