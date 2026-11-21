#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int t, n, l, r, m, ans;

ll DP[25][25][25];

vector<int> v;

int main(){
    /// DP[n][l][r] : 막대를 n개 배치했을때 왼쪽에는 l개가 보이고 오른쪽에는 r개가 보일때
    /// K : 가장 높이가 낮은 막대이고 마지막에 배치한다
    /// K가 가장 왼쪽에 놓일때 : DP[n][l][r] += DP[n-1][l-1][r]
    /// K가 가장 오른쪽에 놓일때 : DP[n][l][r] += DP[n-1][l][r-1]
    /// K가 막대 사이에 놓일때 : DP[n][l][r] += DP[n-1][l][r] * (n-2)
    ///                                                         막대 사이 위치 개수

    DP[1][1][1] = 1;
    for(int i=2; i<=20; i++){
        for(int j=1; j<=i; j++){
            for(int k=1; k<=i; k++){
                DP[i][j][k] = DP[i-1][j-1][k] + DP[i-1][j][k-1] + DP[i-1][j][k]*(i-2);
            }
        }
    }

    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &l, &r);
        printf("%lld\n", DP[n][l][r]);
    }

    return 0;
}
