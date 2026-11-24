#include <bits/stdc++.h>

using namespace std;

int n;

struct data
{
    int x1, y1, x2, y2;
};

data dot[25];

bool ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (y2 - y1) * (x3 - x1) < (y3 - y1) * (x2 - x1);
}

int geometry()
{
    int ans = 0;

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int x1 = dot[i].x1, x2 = dot[i].x2, x3 = dot[j].x1, x4 = dot[j].x2;
            int y1 = dot[i].y1, y2 = dot[i].y2, y3 = dot[j].y1, y4 = dot[j].y2;

            if(ccw(x1, y1, x2, y2, x3, y3) == ccw(x1, y1, x2, y2, x4, y4)) continue;
            if(ccw(x3, y3, x4, y4, x1, y1) == ccw(x3, y3, x4, y4, x2, y2)) continue;

            ans++;
        }
    }

    return ans;
}

void input()
{
    scanf("%d", &n);

    for(int i = 1; i <= n ; i++)
        scanf("%d %d %d %d", &dot[i].x1, &dot[i].y1, &dot[i].x2, &dot[i].y2);
}

int main()
{
    input();

    printf("%d", geometry());

    return 0;
}