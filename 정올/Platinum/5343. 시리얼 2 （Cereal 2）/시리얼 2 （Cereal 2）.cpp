#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
int cereal, edge;
int vt[100005], vt_cycle[100005], vt_cereal[100005];

struct Data{

    int idx, t, ord;

};

vector<Data> v[100005];
queue<int> q;

void cycle(int cur, int pre = -1){
    vt_cycle[cur] = 1;

    for(Data u : v[cur]){
        if(vt_cycle[u.t]){
            if(cereal == -1 && u.t != pre){
                if(u.ord) cereal = u.t;
                else cereal = cur;

                edge = u.idx;
                q.push(u.idx);
                vt_cereal[u.idx] = 1;
            }
        }

        else cycle(u.t, cur);
    }
}

void dfs(int cur){
    vt[cur] = 1;

    for(Data u : v[cur]){
        if(!vt[u.t] && u.idx != edge){
            vt_cereal[u.idx] = 1;
            q.push(u.idx);
            dfs(u.t);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back({i, b, 0});
        v[b].push_back({i, a, 1});
    }

    for(int i=1; i<=m; i++){
         cereal = edge = -1;

         if(!vt[i]){
            cycle(i);

            if(cereal > 0) dfs(cereal);
            else dfs(i);
         }
    }

    for(int i=1; i<=n; i++){
        if(!vt_cereal[i]){
            ans++;
            q.push(i);
        }
    }

    printf("%d\n", ans);

    while(!q.empty()){
        printf("%d\n", q.front());
        q.pop();
    }

    return 0;
}
