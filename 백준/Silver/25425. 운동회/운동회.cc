#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, a, k;

int main()
{
    scanf("%lld %lld %lld %lld", &n, &m, &a, &k);
    a -= k;
	printf("%lld %lld", min(n, a + 1), a / m + (a % m != 0) + 1);

    return 0;
}
