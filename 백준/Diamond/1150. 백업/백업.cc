#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
int com[100005];
int vt[100005], l[100005], r[100005];

ll ans = 0;
ll dist[100005];

struct Data{

    ll d;

    int idx;

    bool operator<(const Data& t)const{
        return d > t.d;
    }

};

priority_queue<Data> pq;

int main()
{
    scanf("%d %d", &n, &k);

    for(int i=1; i<=n; i++){
        scanf("%d", &com[i]);
    }

    for(int i=2; i<=n; i++){
        dist[i] = com[i] - com[i-1];
        pq.push({dist[i], i});
        l[i] = i-1;
        r[i] = i+1;
    }

    dist[1] = dist[n+1] = 1e9;
    l[n+1] = n;
    r[1] = 2;   

    while(k--){
        while(vt[pq.top().idx]) pq.pop();

        Data t = pq.top();
        pq.pop();

        int idx = t.idx;

        vt[l[idx]] = vt[r[idx]] = 1;

        ans += t.d;

        dist[idx] = dist[l[idx]] + dist[r[idx]] - dist[idx];

        pq.push({dist[idx], idx});

        l[idx] = l[l[idx]];
        r[idx] = r[r[idx]];

        r[l[idx]] = idx;
        l[r[idx]] = idx;
    }

    printf("%lld", ans);

    return 0;
}
