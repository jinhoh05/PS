#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, t, ans;

struct Data{

    ll m, p, r;

    bool operator<(const Data &t)const{
        return -t.p*r > -p*t.r;
    }
};

Data score[55];

ll DP[55][100005];

vector<int> v;

int main(){
    scanf("%d %d", &n, &t);

    for(int i=1; i<=n; i++) scanf("%lld", &score[i].m);
    for(int i=1; i<=n; i++) scanf("%lld", &score[i].p);
    for(int i=1; i<=n; i++) scanf("%lld", &score[i].r);

    sort(score+1, score+n+1);

    for(int i=1; i<=n; i++){
        ll m=score[i].m, p=score[i].p, r=score[i].r;
        for(int j=1; j<=t; j++){
            DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            if(r <= j){
                ll sc = m - (j * p);
                DP[i][j] = max(DP[i][j], DP[i-1][j-r] + sc);
            }
        }
    }

    printf("%lld", DP[n][t]);

    return 0;
}
