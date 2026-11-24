#include <bits/stdc++.h>

using namespace std;

const int MOD = 50000000;

int T, X, Y, ans;
int P[16] = {1};

int dx[4] = {1, 1, 0, -1};
int dy[4] = {0, 1, 1, 1};

char vt[MOD], ch_vt[MOD], see[MOD];

int to(int x, int y)
{
    return (x - 1) * 4 + (y - 1);
}

int check(int now)
{
    char &ret = see[now];

    if(ch_vt[now]) return ret;

    ch_vt[now] = 1;

    int A[5][5] = {0, };

    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            int t = to(i, j);
            A[i][j] = now / P[t] % 3;
        }
    }

    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            if(A[i][j])
            {

                for(int k = 0; k < 4; k++)
                {
                    int x = i, y = j, cnt = 0;

                    for(;;)
                    {
                        if(x > 4 || y < 1 || y > 4 || A[i][j] != A[x][y]) break;
                        cnt++;
                        x += dx[k], y += dy[k];
                    }

                    if(cnt > 2) return ret = A[i][j];
                }
            }
        }
    }

    return ret = 0;
}

void dfs(int now, int turn)
{
    if(vt[now]) return;

    vt[now] = 1;

    int A[5][5] = {0, };

    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            int t = to(i, j);
            A[i][j] = now / P[t] % 3;
        }
    }

    for(int j = 1; j <= 4; j++)
    {
        for(int i = 1; i <= 4; i++)
        {
            if(!A[i][j])
            {
                int t = to(i, j);
                int nxt = now + P[t] * turn;
                int val = check(nxt);

                if(val)
                {
                    if(val == 2 && i == X && j == Y) ans++;
                    break;
                }

                dfs(nxt, 3 - turn);

                break;
            }
        }
    }
}

int main()
{
    for(int i = 1; i < 16; i++) P[i] = P[i - 1] * 3;

    scanf("%d%d%d", &T, &X, &Y);

    dfs(P[to(1, T)], 2);

    printf("%d", ans);

    return 0;
}