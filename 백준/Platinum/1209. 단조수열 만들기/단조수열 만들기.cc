#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, x;

ll arr[2005];
ll ans = LONG_MAX;

int main()
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	for(int i = 0; i < 2; i++)
    {
        ll cost = 0;

        priority_queue<ll> pq;

        for(int j = 0; j < n; j++)
        {
            if(!pq.empty() && pq.top() > arr[j])
            {
                cost += pq.top() - arr[j];
                pq.pop();
                pq.push(arr[j]);
            }

            pq.push(arr[j]);
        }

        ans = min(ans, cost);

        reverse(arr, arr + n);
	}

	printf("%lld", ans);

	return 0;
}
