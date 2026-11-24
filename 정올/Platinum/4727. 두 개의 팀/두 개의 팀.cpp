#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll INF = 1e18;

int n;

ll ans = -1e18;
ll cost[200005];
ll A[200005], B[200005], G[200005];

vector<int> v[200005];

void dfs(int node){
    A[node] = cost[node];
    B[node] = -INF;

    priority_queue<ll> pq;

    for(int u : v[node]){
        dfs(u);

        if(A[u] > 0){
            A[node] += A[u];
            B[node] = max(B[node], B[u]);
        }

        else B[node] = max(B[node], G[u]);

        pq.push(G[u]);
    }

    G[node] = A[node];
    ans = max(ans, A[node] + B[node]);

    if(!pq.empty()){
        ll Cost = pq.top();
        pq.pop();

        G[node] = max(G[node], Cost);
        if(!pq.empty()) ans = max(ans, Cost + pq.top());
    }
}

int main()
{
    scanf("%d", &n);

    for(int i=1, cur; i<=n; i++){
        scanf("%lld %d", &cost[i], &cur);

        if(cur != -1) v[cur].push_back(i);
    }

    dfs(1);

    printf("%lld", ans);

    return 0;
}

