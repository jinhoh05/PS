#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
ll arr[1005];
ll ans;

vector<ll> v;

int main()
{
    scanf("%lld %lld", &N, &M);

    for(int i = 1; i <= N; i++)
    {
        scanf("%lld", &arr[i]);
    }

    arr[0] = 0;

    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            v.push_back(arr[i] + arr[j]);
        }
    }

    v.push_back(0);

    sort(v.begin(), v.end());

    for(ll u : v)
    {
        auto p = upper_bound(v.begin(), v.end(), M - u);

        if(p == v.begin()) continue;

        p--;

        ans = max(ans, u + *p);
    }

    printf("%lld", ans);

    return 0;
}
