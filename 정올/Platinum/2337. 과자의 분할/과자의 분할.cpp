#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;

ll t[10005];
ll DP[3][5005][2];

vector<int> v;

int main(){

    for(int i=0; i<3; i++){
        for(int j=0; j<5005; j++){
            DP[i][j][0] = 1e16;
            DP[i][j][1] = 1e16;
        }
    }

    DP[0][0][0] = 0;
    DP[0][0][1] = 1;

    scanf("%d", &n);
    for(int i=1; i<n; i++){
        scanf("%lld", &t[i]);
    }
    m = n/2;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            DP[i%3][j][0] = 1e16;
            DP[i%3][j][1] = 1e16;

            if(j>0){
                DP[i%3][j][0] = min(DP[i%3][j][0], DP[(i-1)%3][j-1][0]);
            }
            DP[i%3][j][1] = min(DP[i%3][j][1], DP[(i-1)%3][j][1]);

            if(j>0){
                DP[i%3][j][0] = min(DP[i%3][j][0], DP[(i-1)%3][j-1][0] + t[i]);
                DP[i%3][j][1] = min(DP[i%3][j][1], DP[(i-1)%3][j-1][0] + t[i]);
            }

            DP[i%3][j][0] = min(DP[i%3][j][0], DP[(i-1)%3][j][1] + t[i]);
            DP[i%3][j][1] = min(DP[i%3][j][1], DP[(i-1)%3][j][1] + t[i]);
        }
    }

    printf("%lld", min(DP[n%3][m][0], DP[n%3][m][1]));

    return 0;
}
