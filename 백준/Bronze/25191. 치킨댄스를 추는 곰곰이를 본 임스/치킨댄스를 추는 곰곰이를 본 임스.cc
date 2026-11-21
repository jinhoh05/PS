#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    printf("%d", min(n, (a / 2) + b));

    return 0;
}
