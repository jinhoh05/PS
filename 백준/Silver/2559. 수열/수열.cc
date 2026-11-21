#include <bits/stdc++.h>

using namespace std;

int n, k, sum, ans;
int arr[100005], p_sum[100005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<k;i++) sum += arr[i];

    p_sum[0] = sum - arr[0];
    ans = sum;
    sum = 0;

    for(int i=0;i<n-k;i++){
        sum = p_sum[i] + arr[i + k];
        p_sum[i + 1] = sum - arr[i + 1];
        ans = max(ans, sum);
        sum = 0;
    }

    cout << ans;

    return 0;
}
