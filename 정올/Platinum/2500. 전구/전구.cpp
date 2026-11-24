#include <bits/stdc++.h>

using namespace std;
int n,k,bulb[205],DP[205][205],cnt,pl=1;

///DP[i][j]=i번쨰 전구부터 j번째 전구까지 모두 같은 전구로 만드는 최솟값


int dynamic(int s, int f){
	if(s == f) return 0;

	if(DP[s][f] != -1) return DP[s][f];
	DP[s][f]=1e9;

	for(int i=s;i<f;i++){
		int tmp = bulb[s] != bulb[i+1] ? 1 : 0;
        DP[s][f] = min(DP[s][f],dynamic(s,i) + dynamic(i+1,f) + tmp);
	}

	return DP[s][f];
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&bulb[i]);
    }

    memset(DP,-1,sizeof(DP));

    printf("%d",dynamic(1,n));

    return 0;
}