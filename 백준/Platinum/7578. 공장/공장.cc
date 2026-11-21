#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAX = 500005;

int n;
int a[MAX], b[MAX];
ll ans;
ll bit[MAX];
pii cable[2 * MAX], factory[MAX];

void update(int x, int val){
    for(;x<=n;x+=(x&-x)) bit[x] += val;
}

ll query(int x){
    ll sum = 0;
    for(;x;x-=(x&-x)) sum += bit[x];
    return sum;
}

void fenwick(){
    for(int i=1;i<=n;i++) factory[i] = cable[a[i]];

    sort(factory + 1, factory + n + 1);

    for(int i=1;i<=n;i++){
        update(factory[i].second, 1);
        ans += (query(n) - query(factory[i].second));
    }
}

void input(){
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> a[i];
        cable[a[i]].first = i;
    }

    for(int i=1;i<=n;i++){
        cin >> b[i];
        cable[b[i]].second = i;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();

    fenwick();

    cout << ans;

    return 0;
}
