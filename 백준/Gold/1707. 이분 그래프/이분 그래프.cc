#include <bits/stdc++.h>

using namespace std;

int k, V, E;
int color[20005];
vector<int> v[20005];

void dfs(int x, int now_color){
    color[x] = now_color;

    for(int u : v[x]){
        if(!color[u]) dfs(u, 3 - now_color);
    }
}

int connect(){
    for(int x=1;x<=V;x++){
        for(int u : v[x]){
            if(color[x] == color[u]) return 0;
        }
    }

    return 1;
}

int main()
{
    cin >> k;

    while(k--){
        for(int j=1;j<=20000;j++) v[j].clear();

        memset(color, 0, sizeof(color));

        cin >> V >> E;

        for(int j=1;j<=E;j++){
            int x, y;
            cin >> x >> y;

            v[x].push_back(y);
            v[y].push_back(x);
        }

        for(int j=1;j<=V;j++){
            if(color[j] == 0) dfs(j, 1);
        }

        if(connect()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}
