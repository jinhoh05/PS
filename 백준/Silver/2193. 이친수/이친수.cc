#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll fibo[95];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    fibo[1] = 1;
    for(int i=2;i<=n;i++) fibo[i] = fibo[i - 1] + fibo[i - 2];

    cout << fibo[n];

    return 0;
}
