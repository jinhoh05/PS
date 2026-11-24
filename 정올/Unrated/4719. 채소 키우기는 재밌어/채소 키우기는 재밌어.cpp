#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
int arr[200005];

ll ans = LONG_MAX;
ll up_sum[200005], down_sum[200005];

void check()
{
    for(int i = 1; i <= n; i++)
        ans = min(ans, max(up_sum[i], down_sum[i]));
}

void calc()
{
    for(int i = 2; i <= n; i++)
    {
        int cost = (arr[i - 1] + 1) - arr[i];

        if(cost > 0) up_sum[i] = up_sum[i - 1] + (ll)cost;
        else up_sum[i] = up_sum[i - 1];
    }

    for(int i = n - 1; i >= 1; i--)
    {
        int cost = (arr[i + 1] + 1) - arr[i];

        if(cost > 0) down_sum[i] = down_sum[i + 1] + (ll)cost;
        else down_sum[i] = down_sum[i + 1];
    }
}

void input()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
}

int main()
{
    input();

    calc();

    check();

    printf("%lld", ans);

    return 0;
}