#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1000000000;
int n, m;
int G[100005];
ll cost, ans;
ll node[100005];

struct data{
    int x, y ,w;
    bool operator <(const data &t)const{
        return w > t.w;
    }
};
vector<data> v;

int get_p(int x){
    if(G[x] == x) return x;
    return G[x] = get_p(G[x]);
}

void push(int x, int y, int w){
    if(x != y){
        ans += node[x] * node[y] * cost;
        ans %= MAX;
        G[y] = x;
        node[x] += node[y];
    }

    cost -= w;
}

void union_find(){
    for(int i=1;i<=n;i++){
        G[i] = i;
        node[i] = 1;
    }

    sort(v.begin(), v.end());

    for(data t : v){
        push(get_p(t.x), get_p(t.y), t.w);
    }

    printf("%d", ans);
}

void input(){
    scanf("%d %d", &n, &m);

    for(int i=1;i<=m;i++){
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);

        v.push_back({x, y, w});
        cost += w;
    }
}

int main(){

    input();

    union_find();

    return 0;
}