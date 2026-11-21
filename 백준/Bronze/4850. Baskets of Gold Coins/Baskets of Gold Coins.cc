#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N, w, d, sum;
int main(){
    while(~scanf("%d %d %d %d", &N, &w, &d, &sum)){
        ll fullWeight = N * (N - 1) / 2 * w;
        ll ans = (fullWeight - sum) / d;
        if(!ans) cout << N << '\n';
        else cout << ans << '\n';
    }
}