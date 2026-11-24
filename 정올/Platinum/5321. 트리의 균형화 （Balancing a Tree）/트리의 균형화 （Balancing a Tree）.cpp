#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;
int T, B;

int main(){

    scanf("%d %d", &T, &B);
    while(T--){
        scanf("%d", &n);

        vector<int> p(n+1), l(n+1), r(n+1);
        for(int i=2; i<=n; i++){
            scanf("%d", &p[i]);
        }

        int ans=0;
        vector<pii> v(n+1);
        pii bal{INT_MAX, INT_MIN};

        for(int i=1; i<=n; i++){
            scanf("%d %d", &l[i], &r[i]);
            v[i] = {r[i], l[i]};
            bal.first = min(bal.first, v[i].first);
            bal.second = max(bal.second, v[i].second);

            if(i > 1){
                v[i].first = min(v[i].first, v[p[i]].first);
                v[i].second = max(v[i].second, v[p[i]].second);
            }

            ans = max(ans, v[i].second - v[i].first);
        }

        ans = max(ans, (bal.second - bal.first + 1) / 2);
        int mid = (bal.first + bal.second) / 2;

        printf("%d\n", ans);
        if(B == 1){
            for(int i=1; i<=n; i++){
                printf("%d ", max(min(mid, r[i]), l[i]));
            }
            printf("\n");
        }
    }

    return 0;
}
