#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll fibo[100], DP[100];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    fibo[1] = fibo[2] = 1;

    for(int i=3;i<=80;i++) fibo[i] = fibo[i - 1] + fibo[i - 2];

    DP[1] = 4;

    for(int i=2;i<=80;i++) DP[i] = DP[i - 1] + fibo[i] * 2;

    cout << DP[n];

    return 0;
}
