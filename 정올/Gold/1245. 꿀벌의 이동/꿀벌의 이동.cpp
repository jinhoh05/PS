#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
ll DP[25][50][50];

int main()
{
    scanf("%d", &N);

    DP[0][21][21] = 1;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 21 - i; j <= 21 + i; j++)
        {
            for(int k = 21 - i; k <= 21 + i; k++)
            {
                if(j % 2 == 1)
                {
                    DP[i][j][k] = DP[i][j][k] + DP[i - 1][j + 1][k] + DP[i - 1][j + 1][k - 1];
                    DP[i][j][k] = DP[i][j][k] + DP[i - 1][j - 1][k] + DP[i - 1][j - 1][k - 1];
                    DP[i][j][k] = DP[i][j][k] + DP[i - 1][j][k + 1] + DP[i - 1][j][k - 1];
                }

                else
                {
                    DP[i][j][k] = DP[i][j][k] + DP[i - 1][j + 1][k] + DP[i - 1][j + 1][k + 1];
                    DP[i][j][k] = DP[i][j][k] + DP[i - 1][j - 1][k] + DP[i - 1][j - 1][k + 1];
                    DP[i][j][k] = DP[i][j][k] + DP[i - 1][j][k + 1] + DP[i - 1][j][k - 1];
                }

                //DP[i][j][k] += 6;
            }
        }
    }

    printf("%lld", DP[N][21][21]);

    return 0;
}
