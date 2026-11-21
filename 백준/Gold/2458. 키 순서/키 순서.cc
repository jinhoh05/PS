#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, m, x, y, cnt;
int h[505][505];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        h[x][y] = 1;
    }

    for(int k = 1; k <= n; k++)
    {
        int sum = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(h[i][k] == 1 && h[k][j] == 1) h[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        int sum = 0;

        for(int j = 1; j <= n; j++)
        {
            if(h[i][j] == 1) sum++;
            if(h[j][i] == 1) sum++;
        }

        if(sum == n - 1) cnt++;
    }

    cout << cnt;

    return 0;
}
