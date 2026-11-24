#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m;
int a, b;

ll ans;
ll x1[300005], x2[300005];
ll y1[300005], y2[300005];

void calc()
{   
    for(int i = 1; i < m; i++) y2[i] += y2[i - 1];

    for(int i = 0; i < n; i++)
    {
        ll s = lower_bound(y1, y1 + m, x1[i] + a) - y1 - 1;
        ll e = upper_bound(y1, y1 + m, x1[i] + b) - y1 - 1;
        ans += x2[i] * (y2[e] - y2[s]);
    }
}

void input()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%lld %lld", &x1[i], &x2[i]);

    scanf("%d", &m);

    for(int i = 0; i < m; i++) scanf("%lld %lld", &y1[i], &y2[i]);

    scanf("%d %d", &a, &b);
}

int main()
{
    input();

    calc();

    printf("%lld", ans);

    return 0;
}