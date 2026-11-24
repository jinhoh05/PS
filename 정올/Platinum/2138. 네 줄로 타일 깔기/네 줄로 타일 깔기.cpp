#include <bits/stdc++.h>

using namespace std;
int n,m,DP[40005][40];

int dynamic(){
	DP[0][0]=1;

	for(int i=0;i<n*4;i++){
		for(int j=0;j<32;j++){
			if(DP[i][j]==0) continue;
			if(j % 2 == 1) DP[i+1][j/2] = (DP[i+1][j/2] + DP[i][j]) % m;
			else{
				if(i % 4 != 3 && (j & 3) == 0) DP[i][j+3] = (DP[i][j+3] + DP[i][j]) % m;
				DP[i][j+17] = (DP[i][j+17] + DP[i][j]) % m;
			}
		}
	}

	return DP[n*4][0];
}

int main()
{
	scanf("%d %d",&n,&m);

	printf("%d",dynamic());

    return 0;
}