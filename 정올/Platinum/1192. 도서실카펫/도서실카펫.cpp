#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int nx, ny;
int mx, my;
int width;
int n;

int lazy[4000005], segment_tree[4000005];

vector<pair<pii, pii>> v;

void update(int node, int l, int r, int ul, int ur, int val)
{
    if(r < ul || ur < l) return;

    int mid = (l + r) / 2;

    if(ul <= l && r <= ur) lazy[node] += val;

    else
    {
        update(node * 2, l, mid, ul, ur, val);
        update(node * 2 + 1, mid + 1, r, ul, ur, val);
    }

    segment_tree[node] = lazy[node];
    if(l < r) segment_tree[node] = lazy[node] + max(segment_tree[node * 2], segment_tree[node * 2 + 1]);
}

void input()
{
    scanf("%d %d %d %d", &nx, &ny, &mx, &my);
    scanf("%d", &width);
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        x1 = min(x1 + width - 1, mx);
        y1 = max(y1 - 1, width - 1);

        x2 = max(x2 - 1, width - 1);
        y2 = min(y2 + width - 1, ny);

        if(x1 < x2 || y2 < y1) continue;

        v.push_back({{x2, 1}, {y1, y2}});
        v.push_back({{x1 + 1, -1}, {y1, y2}});
    }
}

int main()
{
    input();

    sort(v.begin(), v.end());

    int ans = 0;
    for(auto u : v)
    {
        update(1, my, ny, u.second.first, u.second.second, u.first.second);
        ans = max(ans, segment_tree[1]);
    }

    printf("%d", ans);

    return 0;
}
