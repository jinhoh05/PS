#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int MAX = 1e6 + 10;

int n;

ll station[MAX];
ll s1[MAX], s2[MAX];
ll DP1[MAX], DP2[MAX];

struct t
{
    vector<pll> v;
    int d = 0;
};

t sol1, sol2;

ll calc2(pll &cost, ll x)
{
    return cost.first * x + cost.second;
}

ll get(vector<pll> &v, int &d, int x)
{
    while(d + 1 < v.size() && calc2(v[d], x) >= calc2(v[d + 1], x)) d++;
    return calc2(v[d], x);
}

bool check(pll &a, pll &b, pll c)
{
    return 1.0 * (b.second - c.second) / (c.first - b.first) <= 1.0 * (a.second - b.second) / (b.first - a.first);
}

void push(vector<pll> &v, ll a, ll b)
{
    while(v.size() >= 2 && check(v[v.size() - 2], v.back(), pll(a, b))) v.pop_back();
    v.push_back({a, b});
}

void dynamic()
{
    push(sol1.v, 0, 0);

    for(int i = 1; i <= n; i++)
    {
        if(!station[i]) DP1[i] = DP1[i - 1];

        else
        {
            DP1[i] = get(sol1.v, sol1.d, i) + (s1[i] + 1) * i;
            push(sol1.v, -s1[i], DP1[i]);
        }
    }

    push(sol2.v, 0, 0);

    for(int i = n; i >= 1; i--)
    {
        if(!station[i]) DP2[i] = DP2[i + 1];

        else
        {
            DP2[i] = get(sol2.v, sol2.d, n - i + 1) + (s2[i] + 1) * (n - i + 1);
            push(sol2.v, -s2[i], DP2[i]);
        }
    }
}

void calc()
{
    for(int i = 1; i <= n; i++)
        s1[i] = s1[i - 1] + station[i];

    for(int i = n; i >= 1; i--)
        s2[i] = s2[i + 1] + station[i];
}

void output()
{
    ll ans = LONG_MAX;

    for(int i = 0; i <= n; i++)
        ans = min(ans, DP1[i] + DP2[i + 1]);

    printf("%lld", ans);
}

void input()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &station[i]);
}

int main()
{
    input();

    calc();

    dynamic();

    output();

    return 0;
}
