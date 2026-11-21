#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 987654321;
int n, m, x;
int D[1005], P[1005];

vector<pii> v[1005];

void dijkstra(int st){
    priority_queue<pii> q;

    D[st] = 0;

    q.push(make_pair(0, st));

    while(!q.empty()){
        int cost = -q.top().first;
        int u = q.top().second;
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int next = v[u][i].first;
            int next_cost = v[u][i].second;

            if(D[next] > cost + next_cost){
                D[next] = cost + next_cost;
                q.push(make_pair(-D[next], next));
            }
        }
    }

}

void party(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) D[j] = INF;
        dijkstra(i);
        P[i] = D[x];
    }

    for(int j=1;j<=n;j++) D[j] = INF;

    dijkstra(x);

    for(int i=1;i<=n;i++) P[i] = P[i] + D[i];

    sort(P + 1, P + n + 1);
}

void input(){
    scanf("%d %d %d", &n, &m, &x);

    for(int i=1;i<=m;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        v[a].push_back(make_pair(b, c));
    }
}

int main()
{
    input();

    party();

    printf("%d", P[n]);

    return 0;
}
