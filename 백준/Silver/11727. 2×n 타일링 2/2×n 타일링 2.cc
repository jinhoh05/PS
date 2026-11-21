#include <iostream>
using namespace std;
using ll = long long;

int n;
ll DP[1005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    DP[0] = DP[1] = 1;

    for(int i=2;i<=n;i++){
        DP[i] = (DP[i - 1] + DP[i - 2] * 2) % 10007;
    }

    cout << DP[n];

    return 0;
}
