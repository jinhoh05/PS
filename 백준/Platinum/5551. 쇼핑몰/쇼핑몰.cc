#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using pid = pair<int, double>;
using pdi = pair<double, int>;

int N, M, K;

double ans;
double dist[3005];

vector<pid> v[3005];

priority_queue<pdi> pq;

void input()
{
    scanf("%d %d %d", &N, &M, &K);

    for(int i = 0; i < M; i++)
    {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);

        v[a].push_back({b, l});
        v[b].push_back({a, l});
    }

    for(int i = 1; i <= N; i++) dist[i] = 1e9;

    for(int i = 0; i < K; i++)
    {
        int u;
        scanf("%d", &u);

        dist[u] = 0;
        pq.push({0, u});
    }
}

void dijkstra()
{
    while(!pq.empty())
    {
        int u = pq.top().second;
        double sum = -pq.top().first;
        pq.pop();

        if(dist[u] < sum) continue;

        for(pid i : v[u])
        {
            int x = i.first, d = i.second;

            if(sum + d < dist[x])
            {
                dist[x] = sum + d;
                pq.push({-dist[x], x});
            }
        }
    }
}

int main()
{
    input();

    dijkstra();

    for(int i = 1; i <= N; i++)
    {
        for(pid j : v[i])
        {
            int u = j.first, d = j.second;
            ans = max(ans, (dist[i] + dist[u] + d) / (2.0));
        }
    }

    printf("%d", int(ans + 0.5));

    return 0;
}
