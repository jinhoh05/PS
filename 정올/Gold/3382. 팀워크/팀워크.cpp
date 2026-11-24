#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, k, ans;
int arr[10005], DP[10005];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int highest = -1;
        for (int j = 0; j < k; j++)
        {
            if (j + 1 > i) break;
            highest = max(highest, arr[i - j]);
            DP[i] = max(DP[i], DP[i - j - 1] + highest * (j + 1));
        }
    }

    cout << DP[n];

    return 0;
}