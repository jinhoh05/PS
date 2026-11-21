#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <math.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n, ans;
int top, up;

void check(int a)
{
    if(up)
    {
        if(top > a)
        {
            up = 0;
            ans++;
        }
    }

    else
    {
        if(top < a)
        {
            up = 1;
            ans++;
        }
    }

    top = a;
}

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);

        check(a);
    }

    printf("%d", (int)ceil(log10(ans) / log10(2)));

    return 0;
}
