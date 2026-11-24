#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n;

ll ans;

pii dot[100005];

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d %d", &dot[i].second, &dot[i].first);

    sort(dot + 1, dot + n + 1);

    for(int i = 1; i <= n; i++)
    {
        int col1 = dot[i - 1].first, col2 = dot[i].first, col3 = dot[i + 1].first;

        if(col1 == col2 && col3 == col2)
        {
            int val1 = dot[i].second - dot[i - 1].second;
            int val2 = dot[i + 1].second - dot[i].second;

            ans += min(val1, val2);
        }

        else if(col1 == col2) ans += dot[i].second - dot[i - 1].second;

        else if(col3 == col2) ans += dot[i + 1].second - dot[i].second;
    }

    printf("%lld", ans);

    return 0;
}