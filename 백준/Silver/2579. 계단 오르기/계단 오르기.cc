#include <bits/stdc++.h>

using namespace std;

int n;
int stair[305];
int DP[305];

void dynamic(){
    DP[1] = stair[1];
    DP[2] = stair[2] + stair[1];

    int a, b;

    for(int i=3;i<=n;i++){
        a = stair[i] + DP[i - 2];
        b = stair[i] + stair[i - 1] + DP[i - 3];
        DP[i] = max(a, b);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> stair[i];

    dynamic();

    cout << DP[n];

    return 0;
}
