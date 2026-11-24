#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n, arr[100005], k, sum1, ans, sum[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1]+arr[i];
    }
    for(int i = 1; i <= k/2; i++)
    {
        ans += (k-i*2+1) * (arr[k-i+1] - arr[i]);
    }
    sum1 = ans;
    for(int i = 1; i <= n-k; i++)
    {
        sum1 += (k-1) * (arr[i]+arr[i+k]);
        sum1 -= 2 * (sum[i+k-1] - sum[i]);
        ans = min(ans, sum1);
    }
    cout << ans;
}