#include <bits/stdc++.h>

using namespace std;

const int MAX = 10005;

int n, ans;
int a[MAX], b[MAX], renum[MAX];
int elec[MAX], path[MAX];

vector<int> v;

void trace(int x){
    if(x == 0) return;

    trace(path[x]);
    v.push_back(a[b[x]]);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> a[i];
        renum[a[i]] = i;
    }

    for(int i=1;i<=n;i++){
        cin >> b[i];
        b[i] = renum[b[i]];
    }

    for(int i=1;i<=n;i++){
        elec[i] = 1;

        for(int j=1;j<i;j++){
            if(b[j] < b[i]){
                if(elec[i] < elec[j] + 1){
                    elec[i] = elec[j] + 1;
                    path[i] = j;
                }
            }
        }

        if(elec[ans] < elec[i]) ans = i;
    }

    trace(ans);

    sort(v.begin(), v.end());

    cout << v.size() << "\n";

    for(int u : v) cout << u << " ";

    return 0;
}
