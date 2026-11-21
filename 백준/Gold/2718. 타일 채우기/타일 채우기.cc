#include <bits/stdc++.h>

using namespace std;

int t,n,DP[40005][50];

void dynamic(){
	DP[0][0]=1;

	for(int i=0;i<40000;i++){
		for(int j=0;j<32;j++){
			if(DP[i][j]==0) continue;
			if(j % 2 == 1) DP[i+1][j/2] = DP[i+1][j/2] + DP[i][j];
			else{
				if(i % 4 != 3 && (j & 3) == 0) DP[i][j+3] = DP[i][j+3] + DP[i][j];
				DP[i][j+17] = DP[i][j+17] + DP[i][j];
			}
		}
	}
}

int main()
{
    dynamic();

	scanf("%d", &t);

	while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", DP[n*4][0]);
    }

    return 0;
}
