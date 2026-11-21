#include <bits/stdc++.h>

using namespace std;

int n, sum, ans, num = 1e9;
int arr[100005], p_sum[100005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    for(int i=1;i<=arr[n];i++){
        sum = 0;

        for(int j=1;j<=n;j++) sum += abs(i - arr[j]);

        if(sum < num){
            num = sum;
            ans = i;
        }
    }

    cout << ans;

    return 0;
}
