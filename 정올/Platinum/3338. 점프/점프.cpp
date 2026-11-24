#include <bits/stdc++.h>

using namespace std;

int n;

int calc(int x, int y)
{
    int k;
    if(y == 0) return 0;
    if(y == 1) return 1;

    for(k = 1; (1 << k + 1) - 1 <= y;  k++);

    int v = (1 << k) - 1;

    if(v <= x) return k + calc(x - v, y - v);
    if((1 << (k - 1)) - 1 >= x) return max(calc((1 << (k - 1)) - 1, v - 1), k + calc(0, y - v));
    return max(calc(x, v - 1), k + calc(0, y - v));
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int x, y;

        scanf("%d %d", &x, &y);

        printf("%d\n", calc(x, y));
    }

    return 0;
}