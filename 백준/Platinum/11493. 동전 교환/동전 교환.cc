#include <bits/stdc++.h>

using namespace std;

int vertex_num, edge_num;
int adj[502][502];
int capacity[1002][1002];
int flow[1002][1002];
int cost[1002][1002];

void floyd(){
    for(int k=1;k<=vertex_num;k++)
        for(int i=1;i<=vertex_num;i++)
            for(int j=1;j<=vertex_num;j++)
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
}

void clear(queue<int> &q){
    queue<int> empty;
    swap(empty,q);
}

int main(){

    int T;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&vertex_num,&edge_num);

        memset(capacity,0,sizeof(capacity));
        memset(cost,0x6f,sizeof(cost));
        memset(flow,0,sizeof(flow));
        memset(adj,0x0f,sizeof(adj));

        for(int i=1;i<=vertex_num;i++)
            adj[i][i]=0;

        int a,b;
        for(int i=0;i<edge_num;i++){
            scanf("%d %d",&a,&b);
            adj[a][b]=1;
            adj[b][a]=1;
        }

        floyd();

        int src=0, sink=1001;
        vector<vector<int> > graph(1002);
        for(int i=1;i<=vertex_num;i++){
            scanf("%d",&a);
            if(a){
                graph[src].push_back(i);
                graph[i].push_back(src);    // 양방향 엣지.
                capacity[src][i] = 1;
                cost[src][i] = 0;
            }
        }
        for(int i=501;i<=500+vertex_num;i++){
            scanf("%d",&a);
            if(a){
                for(int j=0;j<graph[src].size();j++){
                    int before = graph[src][j];
                    graph[before].push_back(i);
                    graph[i].push_back(before);
                    capacity[before][i] = 0x6fffffff;
                    cost[before][i] = adj[before][i-500];
                    cost[i][before] = -cost[before][i];
                }
                graph[i].push_back(sink);
                graph[sink].push_back(i);
                capacity[i][sink] = 1;
                cost[i][sink] = 0;
            }
        }

        int result=0;
        while(1){

            vector<int> parent(1002,-1);
            parent[src]=src;

            vector<int> dist(1002,0x6fffffff);
            dist[src] = 0;
            
            queue<int> q;
            q.push(src);

            vector<bool> inQueue(1002,false);
            inQueue[src]=true;

            while(!q.empty()){
                int here = q.front(); q.pop();
                inQueue[here]=false;

                for(int i=0;i<graph[here].size();i++){
                    int next = graph[here][i];
                    if(dist[next]>dist[here]+cost[here][next]
                        && capacity[here][next]-flow[here][next]>0){
                        dist[next] = dist[here]+cost[here][next];
                        parent[next] = here;
                        if(!inQueue[next]){
                            q.push(next);
                            inQueue[next] = true;
                        }
                    }
                }
            }

            if(parent[sink]==-1) break;

            int amount=0x6fffffff;
            for(int p=sink;p!=src;p=parent[p])
                amount = min(amount,capacity[parent[p]][p]-flow[parent[p]][p]);

            for(int p=sink;p!=src;p=parent[p]){
                flow[parent[p]][p] += amount;
                flow[p][parent[p]] -= amount;
                result += amount*cost[parent[p]][p];
            }

            clear(q);
        }
        printf("%d\n", result);
        graph.clear();
    }

    return 0;
}