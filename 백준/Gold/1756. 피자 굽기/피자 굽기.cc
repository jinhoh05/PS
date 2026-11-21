#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int d, n, m, ans;
int pz[300005], ov[300005];

vector<int> v;

int main(){

    scanf("%d %d", &d, &n);
    for(int i=0; i<d; i++){
        scanf("%d", &ov[i]);
        if(i && ov[i] > ov[i-1]) ov[i] = ov[i-1];
    }

    for(int i=0; i<n; i++){
        scanf("%d", &pz[i]);
    }

    int cnt=0;
    for(int i=d-1; i>=0; i--){
        if(ov[i] >= pz[cnt]){
            cnt++;
            ans = i+1;
        }
        
        if(cnt == n) break;
    }

    if(cnt != n) ans=0;
    printf("%d", ans);

    return 0;
}
