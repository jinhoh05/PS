#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;

ll max_sz, min_sz;
ll sum[500005], pro, ans;

struct Data{

    ll sz, val;

    bool operator<(const Data &t)const{
        if(sz == t.sz) val < t.val;
        return sz < t.sz;
    }
};

Data art[500005];

vector<int> v;

int main(){

    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &art[i].sz, &art[i].val);
    }

    sort(art+1, art+n+1);

    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + art[i].val;
    }

    min_sz = art[1].sz;
    for(int i=1; i<=n; i++){
        max_sz = art[i].sz;

        ll now = sum[i] - max_sz + min_sz;
        ans = max(ans, now);

        if(i == n) break;

        min_sz = max(min_sz, art[i+1].sz - sum[i]);
    }

    printf("%lld", ans);

    return 0;
}
