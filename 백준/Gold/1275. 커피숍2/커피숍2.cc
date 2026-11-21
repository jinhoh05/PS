#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll tree[100005];
ll arr[100005];
int n, q;

void update(int x, ll val){
    for(;x<=n;x+=x&-x) tree[x] += val;
}

ll query(int x){
    ll sum = 0;
    for(;x;x-=(x&-x)) sum += tree[x];
    return sum;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> q;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
        update(i, arr[i]);
    }

    for(int i=1;i<=q;i++){
        int x, y, a;
        ll b;

        cin >> x >> y >> a >> b;

        if(x > y) swap(x, y);

        cout << query(y) - query(x - 1) << "\n";

        ll c = b - arr[a];
        update(a, c);
        arr[a] = b;
    }


    return 0;
}
