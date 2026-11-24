#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, k, ans;
int dist[100005], vt[1005];

vector<int> v[100005], hipe[1005];

void dijkstra(){
    for(int i=1; i<=n; i++) dist[i]=1e9;
    queue<pii> pq;
    pq.push({0, 1});
    dist[1]=0;

    while(!pq.empty()){
        int cost = pq.front().first;
        int cur = pq.front().second;
        pq.pop();

        if(dist[n] != 1e9) return;

        for(int i:v[cur]){
            if(vt[i]) continue;
            vt[i] = 1;
            for(int n_cur:hipe[i]){
                 if(dist[n_cur] > cost+1){
                    dist[n_cur] = cost+1;
                    pq.push({dist[n_cur], n_cur});
                }
            }
        }
    }
}

int main(){

    scanf("%d %d %d", &n, &k, &m);

    for(int i=1; i<=m; i++){
        for(int j=0; j<k; j++){
            int a;
            scanf("%d", &a);
            v[a].push_back(i);
            hipe[i].push_back(a);
        }
    }

    dijkstra();

    //for(int i=1; i<=n; i++) printf("%d ", dist[i]);

    printf("%d", dist[n]!=1e9 ? dist[n]+1 : -1);

    return 0;
}
