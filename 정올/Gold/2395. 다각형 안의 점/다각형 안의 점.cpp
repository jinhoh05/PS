#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int n, val1, val2, val3, val4;

ll mx, my;

pll dot[100005];

vector<int> v;

stack<int> stk;

int ccw(pll a, pll b, pll c)
{
    ll val = (c.Y - a.Y) * (b.X - a.X) - (b.Y - a.Y) * (c.X - a.X);

    return (val > 0) - (val < 0);
}

void geometry()
{
    int in = 0;

    for(int i = 0; i < n; i++)
    {
        ll x1 = min(dot[i].X, dot[i + 1].X), x2 = max(dot[i].X, dot[i + 1].X);
        ll y1 = min(dot[i].Y, dot[i + 1].Y), y2 = max(dot[i].Y, dot[i + 1].Y);

        if(ccw(dot[i], dot[i + 1], make_pair(mx, my)) == 0 && x1 <= mx && mx <= x2 && y1 <= my && my <= y2)
        {
            printf("BOUNDARY");
            return;
        }
    }

    for(int i = 0; i < n; i++)
    {
        pll a = make_pair(mx, my), b = make_pair(1e9 + 1, 1e9);

        val1 = ccw(dot[i], dot[i + 1], a);
        val2 = ccw(dot[i], dot[i + 1], b);
        val3 = ccw(a, b, dot[i]);
        val4 = ccw(a, b, dot[i + 1]);

        if(val1 == val2 || val3 == val4) continue;
        else in++;
    }

    if(in % 2 == 1) printf("INTERIOR");
    else printf("EXTERIOR");
}


void input()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld %lld", &dot[i].X, &dot[i].Y);

    scanf("%lld %lld", &mx, &my);

    dot[n] = dot[0];
}

int main()
{
    input();

    geometry();

    return 0;
}