#include <bits/stdc++.h>

using namespace std;
int n,DP[100][20];

int dynamic(){
	DP[0][0]=1;

	for(int i=0;i<n*3;i++){
		for(int j=0;j<16;j++){
			if(DP[i][j]==0) continue;
			if(j % 2 == 1) DP[i+1][j/2]+=DP[i][j];
			else{
				if(i % 3 != 2 && (j & 3) == 0) DP[i][j+3]+=DP[i][j];
				DP[i][j+9]+=DP[i][j];
			}
		}
	}

	return DP[n*3][0];
}

int main()
{
	scanf("%d",&n);

	printf("%d",dynamic());

    return 0;
}