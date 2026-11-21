#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 9;

ll DP[33335];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    DP[2] = 2;
    
    for(int i = 3; i <= n; i++)
    {
        DP[i] = (DP[i - 1] * 3) % MOD;
    }
 
    cout << DP[n];
 
    return 0;
}