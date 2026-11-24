#include <bits/stdc++.h>

using namespace std;

vector<int> segment_tree, lazy;

void propa(int left, int right, int node)
{
    if(lazy[node] % 2 == 1)
    {
        segment_tree[node] = (right - left + 1) - segment_tree[node];

        if(left != right)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

void update(int left, int right, int update_left, int update_right, int node)
{
    propa(left, right, node);

    if(update_right < left || right < update_left) return;

    if(update_left <= left && right <= update_right)
    {
        segment_tree[node] = (right - left + 1) - segment_tree[node];

        if(left != right)
        {
            lazy[node * 2] += 1;
            lazy[node * 2 + 1] += 1;
        }

        return;
    }

    int mid = (left + right) / 2;
    update(left, mid, update_left, update_right, node * 2);
    update(mid + 1, right, update_left, update_right, node * 2 + 1);

    segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];

    return;
}

int query(int left, int right, int update_left, int update_right, int node)
{
    propa(left, right, node);

    if(update_right < left || right < update_left) return 0;

    if(update_left <= left && right <= update_right) return segment_tree[node];

    int mid = (left + right) / 2;
    return query(left, mid, update_left, update_right, node * 2) + query(mid + 1, right, update_left, update_right, node * 2 + 1);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int h = (int)ceil(log2(N));
    segment_tree = vector<int>(1 << (h + 1));
    lazy = vector<int>(1 << (h + 1));

    int q, s, e;
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &q, &s, &e);

        if(q == 0) update(1, N, s, e, 1);
        else printf("%d\n", query(1, N, s, e, 1));
    }

    return 0;
}
