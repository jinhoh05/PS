#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, k, num, s, e;
ll bit[1000005], a[1000005];

void update(int x, ll val){
    for(;x<=n;x+=x&-x) bit[x] += val;
}

ll query(int x){
    ll sum = 0;
    for(;x;x-=(x&-x)) sum+=bit[x];
    return sum;
}

int main()
{
    scanf("%lld %lld %lld", &n, &m, &k);

    for(int i=1;i<=n;i++){
       scanf("%lld",&a[i]);
       update(i, a[i]);
    }

    for(int i=1;i<=m + k;i++){
        scanf("%lld %lld %lld",&num, &s, &e);
        if(num == 1){
            update(s, e - a[s]);
            a[s] = e;
        }
        else printf("%lld\n", query(e) - query(s - 1));
    }

    return 0;
}
