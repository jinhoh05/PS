#include <bits/stdc++.h>

using namespace std;

int n, total;
int sum[25][25];
int DP[25][25][2005];

void path()
{
    int cost = 0;

    for(int i = 1; i <= n; i++)
    {
        int Min = 1e9, idx;

        for(int j = 0; j <= n; j++)
        {
            int x = cost + sum[j][i];

            if(DP[i + 1][j][x] == -1) continue;

            if(Min > DP[i + 1][j][x]){
                Min = DP[i + 1][j][x];
                idx = j;
            }
        }

        cost += sum[idx][i];

        printf("%d ", n - idx);
    }
}

int dynamic(int now, int here, int x)
{
    int& ret = DP[now][here][x];

    if(ret != -1) return ret;

    if(now > n) return ret = abs(total - x - x);

    ret = 1e9;

    for(int i = 0; i <= here; i++)
        ret = min(ret, dynamic(now + 1, i, x + sum[i][now]));

    return ret;
}

void input()
{
    scanf("%d", &n);

	for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int x;
            scanf("%d", &x);

            sum[i][j] = sum[i - 1][j] + x;

            total += x;
        }
    }
}

int main()
{
    input();

	memset(DP, -1, sizeof(DP));

	printf("%d\n", dynamic(1, n, 0));

	path();

	return 0;
}