#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, i;

ll x;
ll ans[1000005];

priority_queue<ll> pq;

int main()
{
    //freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        scanf("%lld", &x);

        x -= i;

        pq.push(x);
        pq.push(x);
        pq.pop();

        ans[i] = pq.top();
    }

    /*
    for(int j = 1; j <= n; j++) printf("%d ", ans[j]);
    printf("\n");
    */
    
    i--;

    while(--i)
    {
        if(ans[i] > ans[i + 1]) ans[i] = ans[i + 1];
    }

    for(i = 1; i <= n; i++) printf("%lld\n", ans[i] + i);

    return 0;
}
