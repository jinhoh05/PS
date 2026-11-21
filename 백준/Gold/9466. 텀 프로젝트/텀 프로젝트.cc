#include <bits/stdc++.h>

using namespace std;

int t, n, cnt;
int team[100005], done[100005], vt[100005];

void dfs(int x){
    vt[x] = 1;

    int u = team[x];

    if(!vt[u]) dfs(u);

    else if(!done[u]){
        for(int i=u;i!=x;i=team[i]) cnt++;
        cnt++;
    }

    done[x] = 1;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--){
        memset(vt, 0, sizeof(vt));
        memset(done, 0, sizeof(done));

        cin >> n;

        for(int i=1;i<=n;i++) cin >> team[i];

        cnt = 0;

        for(int i=1;i<=n;i++){
            if(!vt[i]) dfs(i);
        }

        cout << n - cnt << "\n";
    }

    return 0;
}
