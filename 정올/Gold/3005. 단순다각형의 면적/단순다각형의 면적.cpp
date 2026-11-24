#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int n;

ll ans;

pll dot[10005];

void geometry()
{
    ll val1 = 0, val2 = 0;

    dot[n + 1] = dot[1];

    for(int i = 1; i <= n; i++)
        val1 += dot[i].X * dot[i + 1].Y;

    for(int i = 1; i <= n; i++)
        val2 += dot[i].Y * dot[i + 1].X;

    ans = abs(val1 - val2);
}

void input()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%lld %lld", &dot[i].X, &dot[i].Y);
}

int main()
{
    input();

    geometry();

    printf("%lld.%d", ans / 2, ans % 2 == 0 ? 0 : 5);

    return 0;
}