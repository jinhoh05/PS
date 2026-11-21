#include <bits/stdc++.h>

using ull = unsigned long long;
using namespace std;

ull a = 1, b, c, d;

ull calc(ull x){
    ull a1 = a, b1 = b, c1 = c, d1 = d;

    if(x == 0) return 0;

    if(x % 2 == 0){
        calc(x / 2);
        a1 = a, b1 = b, c1 = c, d1 = d;
        a = (a1 * a1) + (b1 * c1);
        b = c = (a1 * b1) + (b1 * d1);
        d = (c1 * b1) + (d1 * d1);
    }

    else if(x % 2 == 1){
        calc(x-1);
        a1 = a, b1 = b, c1 = c, d1 = d;
        a = a1 + b1;
        b = c = a1;
        d = c1;
    }

    return b;
}

int main()
{
    ull x;

    scanf("%llu",&x);

    printf("%lld ", calc(x));

    return 0;
}
