#include <bits/stdc++.h>

using namespace std;

int N;
int bucket[1005];

struct S{

    int u, idx;

    double per;

};

vector<S> pipe[1005];

bool insect(int node, int root, double water)
{
    if(water < bucket[node]) return false;

    for(int i = 0; i < pipe[node].size(); i++)
    {
        int next = pipe[node][i].u;

        if(next == root) continue;

        double new_water = (water * pipe[node][i].per) / 100;

        if(new_water >= 1 && pipe[node][i].idx) new_water *= new_water;

        if(!insect(next, node, new_water)) return false;
    }

    return true;
}

void input()
{
    scanf("%d", &N);

    for(int i = 1; i < N; i++)
    {
        int x, u, idx;

        double per;

        scanf("%d %d %lf %d", &x, &u, &per, &idx);

        pipe[x].push_back({u, idx, per});
        pipe[u].push_back({x, idx, per});
    }

    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &bucket[i]);
    }
}

int main()
{
    input();

    double l = 0, r = 2e9;

    for(int i = 1; i <= 100; i++)
    {
        double mid = (l + r) / 2;

        if(insect(1, -1, mid)) r = mid;
        else l = mid;
    }

    printf("%.4f", l);

    return 0;
}
