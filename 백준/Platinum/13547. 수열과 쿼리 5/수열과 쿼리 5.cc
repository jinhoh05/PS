#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q;
int sn;

ll a[1000005];
ll cnt[1000005], ans[1000005];
ll now;

struct Data{

    ll idx, s, e;

    bool operator<(const Data &t)const{
        if(s/sn != t.s/sn) return s < t.s;
        return e < t.e;
    }

};

Data seq[1000005];

void Minus(ll s, ll e){
    for(ll i=s; i<=e; i++){
        cnt[a[i]]--;
        if(cnt[a[i]]==0) now--;
    }
}

void Plus(ll s, ll e){
    for(ll i=s; i<=e; i++){
        if(cnt[a[i]]==0) now++;
        cnt[a[i]]++;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }

    scanf("%d", &q);
    for(int i=1; i<=q; i++){
        scanf("%lld %lld", &seq[i].s, &seq[i].e);
        seq[i].idx=i;
    }

    sn = sqrt(n);

    sort(seq+1, seq+q+1);

    for(ll i=seq[1].s; i<=seq[1].e; i++){
        if(cnt[a[i]]==0) now++;
        cnt[a[i]]++;
    }
    ans[seq[1].idx]=now;
    ll l = seq[1].s, r = seq[1].e;

    for(int i=2; i<=q; i++){
        if(seq[i].s<l) Plus(seq[i].s, l-1);
        if(seq[i].e>r) Plus(r+1, seq[i].e);
        if(seq[i].s>l) Minus(l, seq[i].s-1);
        if(seq[i].e<r) Minus(seq[i].e+1, r);

        l=seq[i].s;
        r=seq[i].e;
        ans[seq[i].idx]=now;
    }

    for(int i=1; i<=q; i++){
        printf("%lld\n", ans[i]);
    }

    return 0;
}
