#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;

vector<int> v;

ll k, a, b, c, d;

int main(){

    scanf("%lld", &k);
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    if(a*k + b == c*k + d) printf("Yes %lld", a*k+b);
    else printf("No");

    return 0;
}
