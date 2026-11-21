#include <bits/stdc++.h>

using namespace std;
int V, E, K, u, v, w;
int dist[20005];
const int INF = 987654321;

struct st{
    int fin, val;
};

vector<st> graph[20005];
priority_queue<pair<int, int>> q;

void push(int node, int cost){
    for(st x : graph[node]) {
        int f_val = dist[x.fin];
        int s_val = dist[node] + x.val;

        if(s_val < f_val){
            dist[x.fin] = s_val;
            q.push({-1 * s_val, x.fin});
        }
    }
}

void dijkstra(){
    q.push({0, K});

    while(!q.empty()){
        int node = q.top().second;
        int cost = -1 * q.top().first;
        q.pop();

        push(node, cost);
    }
}

void input(){
    scanf("%d %d %d", &V, &E, &K);

    for(int i=1;i<=E;i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
    }

    for(int i=1;i<=V;i++) dist[i] = INF;
    dist[K] = 0;
}

int main(){

    input();

    dijkstra();

    for(int i=1;i<=V;i++){
        if(dist[i] != INF) printf("%d\n", dist[i]);
        else printf("INF\n");
    }

    return 0;
}
