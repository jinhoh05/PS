#include <bits/stdc++.h>

using namespace std;

int n, k;

int main()
{
    scanf("%d %d", &n, &k);

    int val = k * (k + 1) / 2;

    if(n < val) printf("-1");

    else printf("%d", k - ((n - val) % k == 0));

    return 0;
}