#include <bits/stdc++.h>

using namespace std;

int N, P, Q;
int vt[200005];

struct S{

    int x, dist;

};

vector<S> seq;
vector<int> v[200005], A, ans;

bool ascending_comp(const S &a, const S &b)
{
    if(a.dist == b.dist) return a.x < b.x;
    return a.dist < b.dist;
}

void arrange(int x, int dist)
{
    if(vt[x]) return;

    vt[x] = 1;

    seq.push_back({x, dist});

    for(int u : v[x])
        arrange(u, dist + 1);
}

void sorting()
{
    sort(seq.begin(), seq.end(), ascending_comp);

    P = seq.back().dist, Q;

    for(Q = 0; Q < seq.size(); Q++)
    {
        if(seq[Q].dist >= P) break;
    }
}

void calc()
{
    int l = Q, r = seq.size() - 1;

    if(Q % 2 == 1) r -= 1;

    while(l < r)
    {
        l++;
        r--;
    }

    if(l == r) printf("%d", seq[l].x);
    else printf("%d %d", min(seq[l].x, seq[r].x), max(seq[l].x, seq[r].x));
}

void input()
{
    int s, e;

    scanf("%d", &N);

    for(int i = 1; i < N; i++)
    {
        scanf("%d %d", &s, &e);
        v[s].push_back(e);
        v[e].push_back(s);
    }
}

int main()
{
    input();

    arrange(1, 0);

    sorting();

    calc();

    return 0;
}