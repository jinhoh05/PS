#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
ll arr[100005], tree[400005];
const int INF = 2e9;

ll update(int node, int s, int e){
    if(s == e) return tree[node] = arr[s];

    int mid = (s + e) / 2;

    return tree[node] = min(update(node * 2, s, mid), update(node * 2 + 1, mid + 1, e));
}

ll query(int node, int s, int e, int fs, int fe){
    if(e < fs || fe < s) return INF;
    if(fs <= s && e <= fe) return tree[node];

    int mid = (s + e) / 2;

    return min(query(node * 2, s, mid, fs, fe), query(node * 2 + 1, mid + 1, e, fs, fe));
}

void input(){
    scanf("%d %d", &n, &m);

    for(int i=1;i<=n;i++) scanf("%d", &arr[i]);

    update(1, 1, n);
}

int main()
{
    for(int i=1;i<=400000;i++) tree[i] = INF;

    input();

    for(int i=1;i<=m;i++){
        int a, b;
        scanf("%d %d", &a, &b);

        printf("%lld\n", query(1, 1, n, a, b));
    }

    return 0;
}
