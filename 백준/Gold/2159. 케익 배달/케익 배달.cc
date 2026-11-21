#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
int sx, sy;

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

ll DP[100005][5];

struct S
{

    int x, y;

}dot[100005];

int main()
{
    for(int i = 1; i <= 100000; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            DP[i][j] = LLONG_MAX;
        }
    }

    scanf("%d", &N);

    scanf("%d %d", &sx, &sy);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d", &dot[i].x, &dot[i].y);
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int nx = dot[i].x + dx[j], ny = dot[i].y + dy[j];

            if(nx < 0 || nx > 100000 || ny < 0 || ny > 100000) continue;

            for(int k = 0; k < 5; k++)
            {
                int mx = dot[i - 1].x + dx[k], my = dot[i - 1].y + dy[k];

                if(i == 1)
                {
                    mx = sx;    
                    my = sy;
                }

                DP[i][j] = min(DP[i][j], ll(DP[i - 1][k] + abs(nx - mx) + abs(ny - my)));
            }
        }
    }

    printf("%lld", min({DP[N][0], DP[N][1], DP[N][2], DP[N][3], DP[N][4]}));

    return 0;
}
