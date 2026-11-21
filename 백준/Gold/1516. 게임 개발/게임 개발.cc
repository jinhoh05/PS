#include <bits/stdc++.h>

using namespace std;

int n;
int cost[505], ans[505], point[505];

vector<int> v[501];

queue<int> q;

void bfs(){
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int u : v[x]){
            ans[u] = max(ans[u], ans[x] + cost[u]);
            if(--point[u] == 0) q.push(u);
        }
    }
}

void input(){
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> cost[i];

        int before;

        while(1){
            cin >> before;

            if(before == -1) break;

            v[before].push_back(i);
            point[i]++;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();

    for(int i=1;i<=n;i++){
        if(point[i] == 0){
            q.push(i);
            ans[i] = cost[i];
        }
    }

    bfs();

    for(int i=1;i<=n;i++) cout << ans[i] << "\n";

    return 0;

}
