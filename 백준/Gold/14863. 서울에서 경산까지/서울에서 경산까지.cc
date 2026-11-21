#include<bits/stdc++.h>

using namespace std;

int dp[101][100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K, a, b, c, d;
	
    cin >> N >> K;
	
    for (int i = 1; i <= N; i++)
    {
        cin >> a >> b >> c >> d;
		
        if(i == 1)
        {
			dp[i][a] = b;
			dp[i][c] = max(dp[i][c], d);
		}
        
		else 
        {
			for (int j = 0; j <= K; j++) 
            {
				
                if (dp[i - 1][j] == 0) continue; 
				
                else {
					if (j + a <= K) 
						dp[i][j + a] = max(dp[i][j + a], dp[i - 1][j] + b);
					if (j + c <= K)
						dp[i][j + c] = max(dp[i][j + c], dp[i - 1][j] + d);
				}
			}
		}
	}
	
	int m = -1;
	
    for (int i = 1; i <= K; i++)
		m = max(m, dp[N][i]);
	
    cout << m;
    
	return 0;
}