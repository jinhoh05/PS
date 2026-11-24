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

    x += m;
    y -= 2, m++;

    if(y > 0) return x + m * (y / 2);
    
    return x;
}

int main()
{
    ll t, n;

    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld", &n);

        printf("%lld\n", calc(n));
    }

    return 0;
}


/*
#include <iostream>

using namespace std;
using ll = long long;

int n, cnt = 1, sum = 1;
ll triangle[2000005];

int main()
{
    triangle[3] = triangle[5] = 1;

    for(int i = 6; i <= 2000000; i++)
    {
        if(i % 2 == 0) triangle[i] = triangle[i - 3];

        else
        {
            if(cnt == 7)
            {
                cnt = 1;
                sum++;
            }

            triangle[i] = triangle[i - 2] + sum;

            if(i % 12 == 3) triangle[i]++;

            cnt++;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &n);
        printf("%lld\n", triangle[n]);
    }

    return 0;
}
*/