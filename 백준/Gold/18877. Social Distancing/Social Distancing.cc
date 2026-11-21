#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
using pll = pair<ll, ll>;
 
int n, m;

vector<pll> v;
 
bool check(ll x) 
{
    int d = INT_MIN, cnt = 0;
    
    for(int i = 0; i < m; i++)
    {
        ll f = v[i].first, s = v[i].second;
    
        while(d <= s - x) 
        {
            d = max(d + x, f);
            cnt += 1;
        }
    }
    
    return cnt >= n;
}

ll binary()
{
    ll l = 1, r = 1e18, ans = 0;
    
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        
        if (check(mid)) 
        {
            ans = mid;
            l = mid + 1;
        }
        
        else r = mid - 1;
    }
    
    return ans;
}

void input()
{
    cin >> n >> m;
    
    v.resize(m);
    
    for(int i = 0; i < m; i++)
        cin >> v[i].first >> v[i].second;
}
 
int main()
{
    input();
    
    sort(v.begin(), v.end());
    
    cout << binary();

    return 0;
}