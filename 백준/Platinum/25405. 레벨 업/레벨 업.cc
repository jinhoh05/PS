#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll n, m, k, ans;
ll l, r, mid, cnt;
ll lev[100005];

vector<int> v;

int main(){

    scanf("%lld", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld", &lev[i]);
    }
    scanf("%lld %lld", &m, &k);

    sort(lev+1, lev+n+1);

    l = lev[k];
    r = lev[n]+m;

    ans = m*k;

    while(l < r){
        mid = (l+r)/2, cnt = 0;

        for(int i=1; i<=n; i++){
            if(lev[i] >= mid) break;
            if(mid - lev[i] > m) cnt += m;
            else cnt += mid - lev[i];
        }

        if(cnt == m*k){
            r = mid;
            break;
        }
        else if(cnt < m*k) l=mid+1;
        else r=mid;
    }

    int i;
    for(i=1, cnt=0; i<=n; i++){
        if(lev[i] >= r) break;
        if(r - lev[i] > m){
            lev[i] += m;
            cnt += m;
        }
        else{
            cnt += r - lev[i];
            lev[i] = r;
        }
    }

    while(cnt - m*k > 0){
        lev[--i]--;
        cnt--;
    }

    sort(lev+1, lev+n+1);

    for(int i=1; i<=n; i++) printf("%lld ", lev[i]);

    return 0;
}
