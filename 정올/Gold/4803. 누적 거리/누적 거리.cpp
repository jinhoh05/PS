#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Data{
    int a, x;

    bool operator<(const Data& t)const{
        return x < t.x;
    }

}vil[200005];

int n, m;
int q;
ll p[200005], p_calc[200005];

vector<int> pos;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> vil[i].a >> vil[i].x;
    }

    sort(vil, vil+n);

    pos.resize(n);
    for(int i=0; i<n; i++){
        pos[i] = vil[i].x;

        p[i+1] = p[i] + vil[i].a;
        p_calc[i+1] = p_calc[i] + 1ll * vil[i].a * vil[i].x;
    }

    for(int i=0; i<q; i++){
        int k;
        cin >> k;

        int d = lower_bound(pos.begin(), pos.end(), k) - pos.begin();

        ll l = p[d];
        ll l_pos = p_calc[d];

        ll r = p[n] - p[d];
        ll r_pos = p_calc[n] - p_calc[d];

        ll ld = k * l - l_pos;
        ll rd = r_pos - k * r;

        cout << ld + rd << endl;
    }

    return 0;
}