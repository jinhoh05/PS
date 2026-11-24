#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair <int, int>;

int tpa[100005], color[100005];
int vst[100005], q[100005];
int n, k, m;

void lca(int now, int depth, int t)
{
    if (depth > 1000)
        return;
    if (vst[now] == t)
    {
        m = now;
        return;
    }
    vst[now] = t;

    lca(tpa[now], depth + 1, t);
}

void pt(int now, int ed, int col)
{
    if (now == ed)
        return;
    color[now] = col;

    pt(tpa[now], ed, col);
}

void mv(int a, int b)
{
    tpa[a] = b;
}

int ct(int a, int b, int i)
{
    lca(a, 0, i);
    lca(b, 0, i);

    int cnt=0;
    int now = a;
    while (now != m)
    {
        q[cnt++] = color[now];
        now = tpa[now];
    }
    now = b;
    while (now != m)
    {
        q[cnt++] = color[now];
        now = tpa[now];
    }
    sort(q, q+cnt);
    return unique(q, q+cnt) - q;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        int r, a, b, c;
        cin >> r;
        if (r == 1)
        {
            cin >> a >> b >> c;
            lca(a, 0, i);
            lca(b, 0, i);
            pt(a, m, c);
            pt(b, m, c);
        }
        else if (r == 2)
        {
            cin >> a >> b;
            mv(a, b);
        }
        else
        {
            cin >> a >> b;
            cout << ct(a, b, i) << "\n";
        }
    }
}
