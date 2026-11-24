#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, S;

ll calc(ll a, ll b)
{
    if(b == 0) return -a;

    return (2 * b * (a / b)) + calc(b, a % b);
}

int main()
{
    scanf("%lld %lld", &N, &S);

    printf("%lld", N + calc(N - S, S));

    return 0;
}