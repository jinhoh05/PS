#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a[100005], bit[100005];
ll n, c, m, ans;
struct data{
    ll lev, num;
    bool operator<(const data &t)const{
        if(num == t.num) return lev > t.lev;
        return num > t.num;
    }

}seq[100005];

void update(int x, int val){
    for(;x<=n;x+=x&-x) bit[x] += val;
}

ll query(int x){
    ll sum = 0;
    for(;x;x-=(x&-x)) sum += bit[x];
    return sum;
}

void calc(){
    for(int i=2;i<=n;i++){
        a[i] = (m * a[i-1] + c) % (((ll)1 << 31) - 1);
        seq[i].lev = i, seq[i].num = a[i];
    }
    sort(seq + 1, seq + n + 1);

    for(int i=1;i<=n;i++){
        ans += query(seq[i].lev - 1);
        update(seq[i].lev, 1);
    }
}

int main()
{
    a[1] = seq[1].lev = seq[1].num = 1;
    scanf("%lld %lld %lld", &m, &c, &n);

    calc();

    printf("%lld", ans);

    return 0;
}