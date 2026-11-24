#include <bits/stdc++.h>

using namespace std;

int p, n;
int tree[800005], lazy[800005];

struct Data{

    int idx, x, y1, y2;

    bool operator<(const Data &t)const{
        return x < t.x;
    }
};

Data pl[100005];

vector<int> v, ans;

void propa(int node, int l, int r){
    if(lazy[node]){
        tree[node] += lazy[node];

        if(r - l > 1){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

void update(int ul, int ur, int node, int l, int r){
    propa(node, l, r);

    if(ur <= v[l] || ul >= v[r]) return;
    if(r-l <= 1 || (ul <= v[l] && ur >= v[r])){
        lazy[node]++;
        propa(node, l, r);
        return;
    }

    int mid = (l+r)/2;
    update(ul, ur, node*2, l, mid);
    update(ul, ur, node*2+1, mid, r);

    tree[node] = min(tree[node*2], tree[node*2+1]);
}

const int INF = 1e9;
int query(int ul, int ur, int node, int l, int r){
    propa(node, l, r);

    if(ur <= v[l] || ul >= v[r]) return INF;
    if(r-l <= 1 || (ul <= v[l] && ur >= v[r])) return tree[node];
    
    int mid = (l+r)/2;
    return min(query(ul, ur, node*2, l, mid), query(ul, ur, node*2+1, mid, r));
}

int main()
{
    scanf("%d %d", &p, &n);

    for(int i=0; i<n; i++){
        scanf("%d %d %d %d", &pl[i].idx, &pl[i].x, &pl[i].y1, &pl[i].y2);
        v.push_back(pl[i].y1);
        v.push_back(pl[i].y2);
    }

    v.push_back(0);
    sort(pl, pl+n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int sz = v.size()-1;
    for(int i=0; i<n; i++){
        int save = query(pl[i].y1, pl[i].y2, 1, 1, sz);
        if(p - save <= 0) ans.push_back(pl[i].idx);
        update(pl[i].y1, pl[i].y2, 1, 1, sz);
    }

    sort(ans.begin(), ans.end());

    if(ans.empty()) printf("0");
    else for(int u : ans) printf("%d ", u);

    return 0;
}
