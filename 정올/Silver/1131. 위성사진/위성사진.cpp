#include <iostream>

using namespace std;

int w, h;
int cnt;
int vt[1005][100];

char farm[1005][100];

void calc(int x, int y)
{
    if(x < 1 || x > h || y < 1 || y > w) return;
    if(vt[x][y]) return;

    vt[x][y] = 1;

    cnt++;

    calc(x + 1, y);
    calc(x - 1, y);
    calc(x, y + 1);
    calc(x, y - 1);
}

int find_max()
{
    int ans = 0;

    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            cnt = 0;

            if(!vt[i][j]) calc(i, j);

            ans = max(ans, cnt);
        }
    }

    return ans;
}

int main()
{
    scanf("%d %d", &w, &h);

    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            scanf(" %c", &farm[i][j]);

            if(farm[i][j] == '.') vt[i][j] = 1;
        }
    }

    printf("%d", find_max());

    return 0;
}