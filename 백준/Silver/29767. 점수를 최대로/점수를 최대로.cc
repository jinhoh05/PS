#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k, cnt;
ll a[300005];

int main()
{
    cin.tie()->ios_base::sync_with_stdio(0);

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }

    sort(a+1, a+n+1);
    for(int i=n; i>n-k; i--) {
        cnt += a[i];
    }

    cout << cnt;

    return 0;
}
