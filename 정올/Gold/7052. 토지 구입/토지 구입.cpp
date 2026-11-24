#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll inp[505][505];
ll ps[505][505];
ll x, y, a, b;
ll ans = 2e18;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> x >> y >> a >> b;
    if (a > b)
        swap(a, b);
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            cin >> inp[i][j];

    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            ps[i][j] = ps[i-1][j] + inp[i][j];

    for (int x1 = 1; x1 <= x; x1++)
    {
        for (int x2 = x1; x2 <= x; x2++)
        {
            ll arr[505];
            for (int i = 1; i <= y; i++)
                arr[i] = ps[x2][i] - ps[x1-1][i];

            ll y1 = 1, c = 0;
            for (int y2 = 1; y2 <= y; y2++)
            {
                c += arr[y2];
                ans = min(ans, abs(c - a) + abs(c - b));

                while (y1 < y2 && c > b)
                {
                    c -= arr[y1];
                    y1++;
                    ans = min(ans, abs(c - a) + abs(c - b));
                }
            }
        }
    }

    cout << ans;
    return 0;
}