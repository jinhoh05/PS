#include <bits/stdc++.h>

using namespace std;

int n, m;
int w, x, y, c, s, e;
int table[2000][2000];
int tree[2000][2000];

void update(int x, int y, int val)
{
    for(int i = x; i <= n; i += (i & -i))
    {
        for(int j = y; j <= n; j += (j & -j))
        {
            tree[i][j] += val;
        }
    }
}

int query(int x, int y)
{
    int sum = 0;

    for(int i = x; i ; i -= (i & -i))
    {
        for(int j = y; j ; j -= (j & -j))
        {
            sum += tree[i][j];
        }
    }

    return sum;
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &table[i][j]);

            update(i, j, table[i][j]);
        }
    }

    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &w);

        if(w == 0)
        {
            scanf("%d %d %d", &x, &y, &c);

            update(x, y, c - table[x][y]);
            table[x][y] = c;
        }

        else
        {
            scanf("%d %d %d %d", &x, &y, &s, &e);

            printf("%d\n", query(s, e) - query(s, y - 1) - query(x - 1, e) + query(x - 1, y - 1));
        }
    }

    return 0;
}
