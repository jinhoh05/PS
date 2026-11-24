#include <bits/stdc++.h>

using namespace std;

int N;
int standard, MAX;
int l, r = 1e6, mid, cnt;
int vt[505][505], climb[505][505];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init()
{
    for(int i = 0; i <= N + 1; i++)
        for(int j = 0; j <= N + 1; j++)
            if(i < 1 || i > N || j < 1 || j > N) climb[i][j] = -1;

    standard = double(N * N) / 4 * 3;
}

void dfs(int x, int y, int h)
{
    if(x < 1 || x > N || y < 1 || y > N) return;
    if(vt[x][y]) return;

    vt[x][y] = 1;
    cnt++;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if(abs(climb[x][y] - climb[nx][ny]) > h) continue;

        dfs(nx, ny, h);
    }
}

void input()
{
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            scanf("%d", &climb[i][j]);
}

int main()
{
    input();

    init();

    while(l <= r)
    {
        memset(vt, 0, sizeof(vt));

        bool flag = false;

        mid = (l + r) / 2;

        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                cnt = 0;

                dfs(i, j, mid);

                if(cnt >= standard)
                {
                    flag = true;
                    break;
                }
            }

            if(flag) break;
        }

        if(flag) r = mid - 1;
        else l = mid + 1;
    }

    printf("%d", l);

    return 0;
}