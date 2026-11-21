#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 5000005;

ll n, ans, sum, cnt, hap, r_hap, k;
ll vt[MAX], arr[MAX];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++){
        ll a;
        cin >> a;
        sum += a;
        vt[a]++;
    }

    for(int i=1;i<=10000;i++){
        while(vt[i] > 0){
            arr[++cnt] = i;
            vt[i]--;
        }
    }

    if(n % 2 != 0) cout << arr[n / 2 + 1] << " ";

    else{
        ll num = arr[n / 2];
        for(int i=1;i<=n;i++) hap += arr[i] - num;

        ll r_num = arr[n / 2 + 1];
        for(int i=1;i<=n;i++) r_hap += arr[i] - num;

        if(hap > r_hap) cout << r_num << " ";
        else cout << num << " ";
    }

    hap = 0;
    if(sum % n > 0){
        k = sum / n + 1;
        for(int i=1;i<=n;i++) hap += (arr[i] - k) * (arr[i] - k);
    }

    k = sum / n;

    for(int i=1;i<=n;i++) ans += (arr[i] - k) * (arr[i] - k);

    if(hap < ans && hap != 0) cout << k + 1;
    else cout << k;

    return 0;
}
