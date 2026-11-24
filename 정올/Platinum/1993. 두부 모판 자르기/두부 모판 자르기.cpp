#include <bits/stdc++.h>

using namespace std;

int n;
int cur, r, down, mod;
int board[15][15];
int DP[12][12][1 << 12];

int tofu[4][4] = {
	{100, 70, 40, 0},
	{70, 50, 30, 0},
	{40, 30, 20, 0},
	{0, 0, 0, 0}
};

void init()
{
    memset(DP, -1, sizeof(DP));

    cur = (1 << n);
    r = 1 << (n - 1);
    down = 1;
    mod = 1 << (n + 1);
}

int dynamic(int x, int y, int bit)
{
    int &ret = DP[x][y][bit];

    if(ret != -1) return ret;
    if(x == n) return ret = 0;
    if(y == n) return ret = dynamic(x + 1, 0, bit);

    if(ret == -1)
    {
        if(!(bit & cur))
        {
            if(y + 1 < n && !(bit & r))
            {
                int now = board[x][y];
                int next = board[x][y + 1];
                int cost = dynamic(x, y + 2, (bit << 2) % mod) + tofu[now][next];

                ret = max(ret, cost);
            }

            if(x + 1 < n && !(bit & down))
            {
                int now = board[x][y];
				int next = board[x + 1][y];
                int cost = dynamic(x, y + 1, ((bit | down) << 1) % mod) + tofu[now][next];

				ret = max(ret, cost);
			}

            int cost = dynamic(x, y + 1, (bit << 1) % mod);
			ret = max(ret, cost);
        }

        int cost = dynamic(x, y + 1, (bit << 1) % mod);
        ret = max(ret, cost);
    }

    return ret;
}

void input()
{
    char c;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf(" %c", &c);

            board[i][j] = (c == 'F' ? 3 : c - 'A');
        }
    }
}

int main()
{
    input();

    init();

    printf("%d", dynamic(0, 0, 0));

    return 0;
}