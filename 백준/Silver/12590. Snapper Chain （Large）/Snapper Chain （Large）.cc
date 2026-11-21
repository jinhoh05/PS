#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int main()
{
    scanf("%d", &t);

    for(int i = 1; i <= t; i++)
    {
        scanf("%d %d", &n, &k);

        int bit = (1 << n) - 1;

        printf("Case #%d: ", i);

        if((bit & k) == bit) printf("ON\n");

        else printf("OFF\n");
    }

    return 0;
}
