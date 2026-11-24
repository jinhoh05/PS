#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, ans = 1e9;
int tile[55][55];

void check(int x, int y, int oldx, int oldy, int lev)
{
    if(x == n && y == n)
    {
        ans = min(ans, lev);
        return;
    }

    if(x < 1 || y < 1 || x > n || y > n) return;

    if(tile[x][y] == 0)
    {
        if(oldx > x)
        {
            int num = tile[x][y + 1];

            if(num == 1 || num == 3 || num == 5) check(x, y + 1, x, y, lev + 1);

            else return;
        }

        else
        {
            int num = tile[x + 1][y];

            if(num == 2 || num == 3 || num == 4) check(x + 1, y, x, y, lev + 1);

            else return;
        }
    }

    else if(tile[x][y] == 1)
    {
        if(oldx > x)
        {
            int num = tile[x][y - 1];

            if(num == 0 || num == 2 || num == 5) check(x, y - 1, x, y, lev + 1);

            else return;
        }

        else
        {
            int num = tile[x + 1][y];

            if(num == 2 || num == 3 || num == 4) check(x + 1, y, x, y, lev + 1);

            else return;
        }
    }

    else if(tile[x][y] == 2)
    {
        if(oldy > y)
        {
            int num = tile[x - 1][y];

            if(num == 0 || num == 1 || num == 4) check(x - 1, y, x, y, lev + 1);

            else return;
        }

        else
        {
            int num = tile[x][y + 1];

            if(num == 1 || num == 3 || num == 5) check(x, y + 1, x, y, lev + 1);

            else return;
        }
    }

    else if(tile[x][y] == 3)
    {
        if(oldy < y)
        {
            int num = tile[x - 1][y];

            if(num == 0 || num == 1 || num == 4) check(x - 1, y, x, y, lev + 1);

            else return;
        }

        else
        {
            int num = tile[x][y - 1];

            if(num == 0 || num == 2 || num == 5) check(x, y - 1, x, y, lev + 1);

            else return;
        }
    }

    else if(tile[x][y] == 4)
    {
        if(oldx < x)
        {
            int num = tile[x + 1][y];

            if(num == 2 || num == 3 || num == 4) check(x + 1, y, x, y, lev + 1);

            else return;
        }

        else
        {
            int num = tile[x - 1][y];

            if(num == 0 || num == 1 || num == 4) check(x - 1, y, x, y, lev + 1);

            else return;
        }
    }

    else if(tile[x][y] == 5)
    {
        if(oldy < y)
        {
            int num = tile[x][y + 1];

            if(num == 1 || num == 3 || num == 5) check(x, y + 1, x, y, lev + 1);

            else return;
        }

        else
        {
            int num = tile[x][y - 1];

            if(num == 0 || num == 2 || num == 5) check(x, y - 1, x, y, lev + 1);

            else return;
        }
    }
}

void change()
{
    if(k == 0)
    {
        int num1 = tile[n][n], num2 = tile[1][1];

        if((num1 == 2 || num1 == 5) && (num2 == 1 || num2 == 5)) check(1, 1, 0, 0, 1);

        return;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int h = 0; h <= 5; h++)
            {
                if(tile[i][j] == h) continue;

                int val = tile[i][j];

                tile[i][j] = h;

                int num1 = tile[n][n], num2 = tile[1][1];

                if((num1 == 2 || num1 == 5) && (num2 == 1 || num2 == 5)) check(1, 1, 0, 0, 1);

                tile[i][j] = val;
            }
        }
    }
}

void input()
{
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &tile[i][j]);
}

int main()
{
    input();

    change();

    printf("%d", ans == 1e9 ? -1 : ans);

    return 0;
}