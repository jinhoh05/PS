#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
ll a, b, c, sum, val = LLONG_MAX;
ll koi[100005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    ll l = 1, r = n;

    for(int i=1;i<=n;i++) cin >> koi[i];

    sort(koi + 1, koi + n + 1);

    for(int i=1;i<=n;i++){
        l = i + 1;
        r = n;

        while(l < r){
            sum = koi[i] + koi[l] + koi[r];

            if(abs(sum) < val){
                val = abs(sum);
                a = koi[i];
                b = koi[l];
                c = koi[r];
            }

            if(sum < 0) l++;
            else r--;
        }
    }

    cout << a << " " << b << " " << c;

    return 0;
}
