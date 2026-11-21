#include<iostream>

using namespace std;

const int MAX = 1000000000;
int n;
int w[20][20];
int DP[20][1 << 16 + 1];

int TSP(int node, int vt){
	int len = DP[node][vt];

	if(len != 0) return len;

	if(vt == (1 << n) - 1){
		if(w[node][0] != 0) return w[node][0];
		return MAX;
	}

	len = MAX;

	for(int i=0;i<n;i++){
		if(vt & 1 << i || w[node][i] == 0) continue;

		int res = TSP(i ,(vt | 1 << i)) + w[node][i];

		if(res < len) len = res;
	}

	DP[node][vt] = len;

	return len;
}

int main(){

	scanf("%d", &n);

	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&w[i][j]);
        }
    }

	printf("%d", TSP(0, 1));

	return 0;
}
