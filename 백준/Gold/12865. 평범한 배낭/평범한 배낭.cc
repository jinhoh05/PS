#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, K;
int DP[105][100005], arr[105][100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N >> K;

	for(int i = 1; i <= N; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	for(int i = 1; i <= N; i++)
	{
        int w = arr[i][0], c = arr[i][1];

		for(int j = 0; j <= K; j++)
		{
			if(j < w) DP[i][j] = DP[i - 1][j];
			else DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w] + c);
		}
	}

    cout << DP[N][K];

    return 0;
}
