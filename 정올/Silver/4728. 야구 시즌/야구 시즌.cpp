#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n, m, k, d;
        scanf("%d %d %d %d", &n, &m, &k, &d);
	
	///같은 리그 수 : mC2 * n * k * B
        ///다른 리그 수 : n * m * m * (n - 1) / 2 * B

        ll cnt = m * (m - 1) * n * k / 2;
	cnt += n * m * m * (n - 1) / 2;

        int ans = d / cnt;

	printf("%lld\n", ans == 0 ? -1 : ans * cnt);
    }
}
