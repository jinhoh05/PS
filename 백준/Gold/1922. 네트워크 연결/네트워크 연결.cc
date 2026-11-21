#include<bits/stdc++.h>

using namespace std;

int n, m, ans;
int G[100005];

struct st{
    int a, b, c;
    bool operator<(const st &t)const{
        if(c == t.c && a == t.a) return b < t.b;
        else if(c == t.c) return a < t.a;
        return c < t.c;
    }
};

vector<st> v;

int find_p(int x){
    if(G[x] == x) return x;
    else return G[x] = find_p(G[x]);
}

void union_p(int x, int y){
    x = find_p(x);
    y = find_p(y);

    if(x != y) G[y] = x;
}

int get_p(int x, int y){
    x = find_p(x);
    y = find_p(y);

    if(x == y) return 1;
    else return 0;
}

void spanner(){
    for(int i=1;i<=n;i++) G[i] = i;

    for(int i=0;i<m;i++){
        if(!get_p(v[i].a, v[i].b)){
            union_p(v[i].a, v[i].b);
            ans += v[i].c;
        }
    }
}

void input(){
    cin >> n >> m;

    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;

        v.push_back({a, b, c});
    }

    sort(v.begin(), v.end());
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();

    spanner();

    printf("%d", ans);

    return 0;
}
