#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;

struct vbar{
    int x;
    int yd, yu;

    bool operator<(const vbar &t)const{
        return x < t.x;
    }
};

vector<vbar> vbars;
vector<int> ypos;

const int LN = 2e5 + 1;
struct Seg{
    int sum[LN*4];
    int lazy[LN*4];

    void update(int yd, int yu){
        update(yd, yu, 1, 0, N);
    }

    void update(int ul, int ur, int node, int l, int r){
        propagate(node, l, r);
        if(ul >= ypos[r] || ur <= ypos[l]) return;
        if(ul <= ypos[l] && ypos[r] <= ur){
            lazy[node] ^= 1;
            propagate(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(ul, ur, node * 2, l, mid);
        update(ul, ur, node * 2 + 1, mid, r);
        sum[node] = sum[node * 2] + sum[node * 2 + 1];
    }

    void propagate(int node, int l, int r){
        if(!lazy[node]) return;
        if(r - l > 1){
            lazy[node * 2] ^= 1;
            lazy[node * 2 + 1] ^= 1;
        }
        lazy[node] ^= 1;
        sum[node] = ypos[r] - ypos[l] - sum[node];
    }

    int getY(){
        return sum[1];
    }
}tree;

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        vbars.push_back({x1, y1, y2});
        vbars.push_back({x2, y1, y2});

        ypos.push_back(y1);
        ypos.push_back(y2);
    }

    sort(vbars.begin(), vbars.end());
    sort(ypos.begin(), ypos.end());

    ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());

    ll px = 0, area = 0;

    N = ypos.size() - 1;

    for(vbar &v : vbars)
    {
        area += (v.x - px) * tree.getY();
        tree.update(v.yd, v.yu);
        px = v.x;
    }

    printf("%lld", area);

    return 0;
}
