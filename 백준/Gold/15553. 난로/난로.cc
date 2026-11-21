#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, k, ans;
int Time[100005];

vector<int> v;

int main(){

    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d", &Time[i]);
    }

    for(int i=2; i<=n; i++){
        v.push_back(Time[i] - Time[i-1]);
    }

    sort(v.begin(), v.end());

    if(k < n){
        for(int i=0; i<n-k; i++){
            ans += v[i];
        }
        printf("%d", ans+k);
    }

    else printf("%d", n);

    return 0;
}
