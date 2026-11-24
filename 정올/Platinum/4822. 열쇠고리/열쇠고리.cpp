#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;
int DP[2005][4005];

vector<int> v;

struct Data{

    int idx, a, b;

};

Data key[2005];

/// D[i][j] = i번 스트랩까지 고려
///           단자가 j개일때 행복도 max
/// i+1번째 사용 * D[i][j] = D[i+1][j]
/// i번째 사용
/// k = min(j + B(i+1) - 1, n)
/// D[i][j] + A(i+1) -> D[i+1][k]

int main(){

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &key[i].a, &key[i].b);
    }

    for(int i=0; i<=4000; i++) DP[0][i] = -21e8;
    DP[0][2001]=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<=4000; j++) DP[i+1][j] = -21e8;

        for(int j=0; j<=4000; j++){
            int k = j + (key[i].a-1);
            if(k < 0) continue;
            if(k > 4000) k = 4000;

            DP[i+1][k] = max(DP[i+1][k], DP[i][j] + key[i].b);
            DP[i+1][j] = max(DP[i+1][j], DP[i][j]);
        }
    }

    int ans=0;
    for(int i=2000; i<=4000; i++) ans = max(ans, DP[n][i]);
    printf("%d", ans);

    return 0;
}
