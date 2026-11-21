#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
ll a, b, sum, val, ans = 987987654321;
ll koi[100005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    int l = 1, r = n;

    for(int i=1;i<=n;i++) cin >> koi[i];

    sort(koi + 1, koi + n + 1);

    while(l < r){
        sum = koi[l] + koi[r];
        val = abs(sum);

        if(ans > val){
            ans = val;
            a = koi[l];
            b = koi[r];
        }

        if(sum < 0) l++;
        else r--;
    }

    cout << a << " " << b;

    return 0;
}
