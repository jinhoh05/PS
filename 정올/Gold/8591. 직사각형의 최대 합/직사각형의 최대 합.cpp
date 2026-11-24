#include <bits/stdc++.h>

using namespace std;
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
int rec[805][805];

ll y[805][805];
ll ans=LLONG_MIN;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> rec[i][j];
            y[i][j] = y[i-1][j] + rec[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            ll cur = y[j][1] - y[i-1][1], temp = y[j][1] - y[i-1][1];
            
            for(int k=2; k<=m; k++){
                ll sum = y[j][k] - y[i-1][k];
                cur = max(sum, cur + sum);
                temp = max(temp, cur);
            }

            ans = max(ans, temp);
        }
    }

    cout << ans;

    return 0;
}