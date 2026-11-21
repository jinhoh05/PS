#include <bits/stdc++.h>

using namespace std;
/// n이 100만 이기 때문에 graph를 먼저 채우면 시간초과가 난다.
/// 초기에 입력받은 값을 queue에 넣어 multi source bfs를 진행한다.
/// 가장 멀리 간 노드가 답이 되므로 거리를 저장해준다.

/// 핵심은 그래프를 먼저 만드는 것이 아니라 큐에 들어가서 그때마다 그래프를 구성하는 것이다
 
const int MAX = 1000005;
int n, m, ans;
int vt[MAX], dist[MAX];
queue<int> q;

void multi_bfs(){
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i=0;i<=20;i++) {
            int v = u ^ (1 << i);
            if(v <= n && dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    fill(dist, dist + n + 1, -1);

    for(int i=1;i<=m;i++){
        int a;
        scanf("%d", &a);
        q.push(a);
        dist[a] = 0;
    }

    multi_bfs();

    for(int i=0;i<=n;i++) ans = max(ans, dist[i]);
    printf("%d", ans);

    return 0;
}
