#include <bits/stdc++.h>

using namespace std;

int N, H, ans = 1e9;
int DP[105][55005];

struct S{

    int p, c;

}pack[105];

int main()
{
    scanf("%d %d", &N, &H);

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &pack[i].p, &pack[i].c);
    }

    memset(DP, 15, sizeof(DP));

    DP[0][0] = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j + pack[i].p <= 55000; j++)
        {
            DP[i][j + pack[i].p] = min(DP[i][j + pack[i].p], DP[i][j] + pack[i].c);
            DP[i + 1][j] = min(DP[i + 1][j], DP[i][j]);

            if(j >= H) ans = min(ans, DP[i][j]);
        }
    }

    printf("%d", ans);

    return 0;
}
