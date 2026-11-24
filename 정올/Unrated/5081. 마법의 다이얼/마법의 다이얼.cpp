#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M, R;
int m, l;

ll v1, a1;
ll ans, now;

vector<int> V[500005];

map<int, int> mp;

int main()
{
    scanf("%d %d %d", &N, &M, &R);

    for(int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        V[x].push_back(y);
    }

    for(int i = 0; i < M; i++)
    {
        sort(V[i].begin(), V[i].end());

        auto &v = V[i];
        int sz = v.size();
	int w1 = min(v[0], R - v.back());
	int w2 = min(v[0] + 1, R - v.back() - 1);

	a1 += (w1 - w2);
	v1 += w1;

	for(int u : v) mp[u] += 2;

	for(int j = 0; j < sz; j++)
        {
       	    ll s = v[j] + v[(j + 1) % sz];

	    if(j == sz - 1) s += R;

	    int lv = (s >> 1), rv = ((s + 1) >> 1);
	    lv %= R, rv %= R;

	    if(lv == rv) mp[lv] -= 2;
	    else
            {
                mp[lv]--;
                mp[rv]--;
            }
        }
    }

    ans = now = v1;

    int p = 0;
    
    for(auto [x, val] : mp)
    {
	now += (x - p) * a1;
	a1 += val;
	p = x;

	ans = min(ans, now);
    }

    printf("%lld", ans);

    return 0;
}
