#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll calc(ll n)
{
    if(n == 1 || n == 2 || n == 4) return 0;

    if(n % 2 == 0) n -= 3;
    
    ll m = n / 12;
        
    if(n - (n / 12 * 12) - 3 < 0) m -= 1;

    ll x = (m * (1 + m) / 2) * 6 + 1;

    ll y = n - (m * 12) - 3;

    if(y == 0) return x;

    if(y == 2) return x + m;

    if(y > 2)
    {
        x += m;
        y -= 2, m++;

        return x + m * (y / 2);
    }
}

int main()
{
    ll n;
    
    scanf("%lld", &n);

    printf("%lld\n", calc(n));

    return 0;
}