#include <bits/stdc++.h>

using namespace std;

int n, m, ans, now;
int G[100005];

int union_p(int x){
    if(x == G[x]) return x;
    return G[x] = union_p(G[x]);
}

void get_p(int x, int y){
    x = union_p(x);
    y = union_p(y);
    G[x] = y;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=1;i<=n;i++) G[i] = i;

    for(int i=1;i<=m;i++){
        int p;
        cin >> p;

        if(now) continue;

        int union_find = union_p(p);

        if(union_find == 0){
            now = 1;
            continue;
        }

        else{
            ans++;
            get_p(union_find, union_find - 1);
        }
    }

    cout << ans;

    return 0;
}
