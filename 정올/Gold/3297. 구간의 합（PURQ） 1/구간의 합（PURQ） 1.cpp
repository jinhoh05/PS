#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n, m, num, s, e;
ll bit[1000005], a[1000005];

void update(int x, int val){
    for(;x<=n;x+=x&-x) bit[x] += val;
}

ll query(int x){
    ll sum = 0;
    for(;x;x-=(x&-x)) sum+=bit[x];
    return sum;
}

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
       scanf("%d",&a[i]);
       update(i, a[i]);
    }

    scanf("%d",&m);

    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&num, &s, &e);
        if(num == 1){
            update(s, e - a[s]);
            a[s] = e;
        }
        else printf("%lld\n", query(e) - query(s - 1));
    }

    return 0;
}