#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
int chalk[100005];
int G[100005], R[100005];

vector<pii> v1;
vector<int> v2[100005];

int get_p(int x){
    if(G[x] == x) return x;
    return G[x] = get_p(G[x]);
}

void union_find(int s, int e){
    s = get_p(s);
    e = get_p(e);

    if(s == e) return;

    if(R[s] > R[e]) swap(s, e);

    R[e] += R[s];
    G[s] = e;
}

int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        scanf("%d", &chalk[i]);
        v1.push_back({-chalk[i], i});
    }

    for(int i=1; i<n; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        v2[s].push_back(e);
        v2[e].push_back(s);
    }

    sort(v1.begin(), v1.end());

    for(int i=1; i<=n ;i++) G[i]=i, R[i]=1;

    ll ans = 0;
    for(pii i : v1){
        int cost = -i.first, idx = i.second;
        for(int u : v2[idx]){
            if(chalk[u] >= cost) union_find(idx, u);
        }
        ans = max(ans, (ll)cost * R[get_p(idx)]);
    }

    printf("%lld",ans);

    return 0;
}
