#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, t;
ll DP[10][100005];

void init(){
    for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			DP[i][j] = -1e9;
        }
    }
}

void dynamic(){
	DP[0][0] = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<10;k++){
                int tmp1 = (j * 10 + k) % m;
				DP[i + 1][tmp1] = max(DP[i + 1][tmp1], 10 * DP[i][j] + k);
			}
			int tmp2 = (j * 100 + 11) % m;
			DP[i + 1][tmp2] = max(DP[i + 1][tmp2], 100 * DP[i][j] + 11);
		}
	}

	printf("%lld\n", DP[n][0]);
}

int main(){

    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        scanf("%d %d", &n, &m);
        init();
        dynamic();
    }

	return 0;
}
