#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
int k, val1, val2, num;
int point[1005], ans[1005];

vector<int> v[1005];

queue<int> q;

void push(int x){
    for(int u : v[x]){
        point[u]--;
        if(point[u] == 0) q.push(u);
    }
}

void topological(){
    while(!q.empty()){
        int t = q.front();
        q.pop();

        ans[++cnt] = t;
        push(t);
    }

    if(cnt != n) cout << 0;
    else{
        for(int i=1;i<=n;i++) cout << ans[i] << "\n";
    }
}

void input(){
    cin >> n >> m;

    for(int i=1;i<=m;i++){
        cin >> k >> val2;

        for(int j=2;j<=k;j++){
            cin >> num;
            val1 = num;

            v[val2].push_back(val1);
            point[val1]++;

            val2 = val1;
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
            point[i]--;
            q.push(i);
        }
    }

    topological();

    return 0;
}
