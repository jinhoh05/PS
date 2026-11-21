#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1000000007;
int n;
ll ans = 1;

int main()
{
    scanf("%d", &n);

    for(int i=1;i<=n+2;i++) ans = (ans * 2) % MAX;

    printf("%d", ans - 5);

    return 0;
}
