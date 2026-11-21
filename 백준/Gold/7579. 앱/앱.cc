#include <bits/stdc++.h>

using namespace std;

int n, m, sum;
int mem[105], cost[105];
int DP[10005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> mem[i];

    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
        sum += cost[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = sum; j >= cost[i]; j--)
        {
            DP[j] = max(DP[j], DP[j - cost[i]] + mem[i]);
        }
    }

    int i = 0;

    for(i = 0; i < sum && DP[i] < m; i++);

    cout << i;

    return 0;
}
