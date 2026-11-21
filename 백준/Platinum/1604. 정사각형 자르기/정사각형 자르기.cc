#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const double EPS = 1e-6;

int n, ans = 1;

struct t{
    ll x1, y1, x2, y2;
}dot[110];

int ccw(pll a, pll b, pll c)
{
    ll val = (c.Y - a.Y) * (b.X - a.X) - (b.Y - a.Y) * (c.X - a.X);

    return (val > 0) - (val < 0);
}

bool calc(int i, int j, double& x, double& y)
{
    ll x1 = dot[i].x1, x2 = dot[i].x2, x3 = dot[j].x1, x4 = dot[j].x2;
    ll y1 = dot[i].y1, y2 = dot[i].y2, y3 = dot[j].y1, y4 = dot[j].y2;

    if(((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)) == 0) return false;

    x = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
    x /= (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    y = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
    y /= (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if(min(x1, x2) <= x && x <= max(x1, x2) && min(x3, x4) <= x && x <= max(x3, x4))
        if(min(y1, y2) <= y && y <= max(y1, y2) && min(y3, y4) <= y && y <= max(y3, y4)) return true;

    return false;
}

void find_cross(double& x, double& y)
{
    if(x > 10 && fabs(x - 10) <= EPS) x = 10.0;
    else if(x < -10 && fabs(x + 10) <= EPS) x = -10.0;

    if(y > 10 && fabs(y - 10) <= EPS) y = 10.0;
    else if(y < -10 && fabs(y + 10) <= EPS) y = -10.0;
}

void geometry()
{
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        double x = 0, y = 0;

        if(!calc(i, n, x, y) && !calc(i, n + 1, x, y) && !calc(i, n + 2, x, y) && !calc(i, n + 3, x, y)) continue;

        find_cross(x, y);

        if((dot[i].x2 - dot[i].x1) != (dot[i].y2 - dot[i].y1))
            if((x == -10 && y == -10) || (x == -10 && y == 10) || (x == 10 && y == -10) || (x == 10 && y == 10)) continue;

        for(int j = i - 1; j >= 0; j--)
        {
            if(!calc(i, j, x, y)) continue;
            if(-10 < x && x < 10 && -10 < y && y < 10) cnt++;
        }

        ans += cnt + 1;
    }
}

void input()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld %lld %lld %lld", &dot[i].x1, &dot[i].y1, &dot[i].x2, &dot[i].y2);

    dot[n] = t{-10, -10, 10, -10};
    dot[n + 1] = t{10, -10, 10, 10};
    dot[n + 2] = t{10, 10, -10, 10};
    dot[n + 3] = t{-10, 10, -10, -10};
}

int main()
{
    input();

    geometry();

    printf("%d", ans);

    return 0;
}
