#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
int speed[500005];
int tree[2000005];

vector<pair<int, int>> v;

void update(int x, int val)
{
    for(;x<=N;x+=(x&-x)) tree[x] += val;
}

int query(int x)
{
    int sum = 0;

    for(;x;x-=(x&-x)) sum += tree[x];

    return sum;
}


int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &speed[i]);
    }

    for(int i = 0; i < N; i++)
    {
        v.push_back({speed[i], i + 1});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++)
    {
        v[i].first = i + 1;
        swap(v[i].first, v[i].second);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++)
    {
        int p = v[i].second;

        printf("%d\n", (i + 1) - query(p - 1));

        update(p, 1);
    }

    return 0;
}
