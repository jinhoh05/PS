#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int score[505], point[505];
int vt[505][505];

void check(int a, int b){
    if(vt[a][b]){
        vt[a][b] = 0;
        vt[b][a] = 1;

        point[a]++;
        point[b]--;
    }

    else{
        vt[a][b] = 1;
        vt[b][a] = 0;

        point[a]--;
        point[b]++;
    }
}

void topol(){
    queue<int> q;
    vector<int> ans;

    for(int i=1;i<=n;i++){
        if(point[i] == 0) q.push(i);
    }

    for(int k=0;k<n;k++){
        if(q.empty()) break;

        int t = q.front();
        q.pop();

        ans.push_back(t);

        point[t]--;

        for(int i=1;i<=n;i++){
            if(vt[t][i]) point[i]--;
            if(point[i] == 0) q.push(i);
        }
    }

    if(ans.size() == n){
        for(int u : ans) cout << u << " ";
        cout << "\n";
    }

    else cout << "IMPOSSIBLE" << "\n";
}

void input(){
    cin >> n;

    for(int i=0;i<n;i++) cin >> score[i];

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            vt[score[i]][score[j]] = 1;
            point[score[j]]++;
        }
    }

    cin >> m;

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        check(a, b);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--){
        memset(point, 0, sizeof(point));
        memset(vt, 0, sizeof(vt));

        input();

        topol();
    }

    return 0;
}
