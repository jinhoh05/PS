#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, e, ans;
int G[10005];
vector<pair<int, pii>> v;

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

    for(int i=0;i<e;i++){
        if(get_p(v[i].second.first, v[i].second.second) == false){
            union_p(v[i].second.first, v[i].second.second);
            ans += v[i].first;
        }
    }
}

void input(){
    cin >> n >> e;

    for(int i=0;i<e;i++){
        int a, b, c;
        cin >> a >> b >> c;

        v.push_back(make_pair(c, make_pair(a, b)));
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
