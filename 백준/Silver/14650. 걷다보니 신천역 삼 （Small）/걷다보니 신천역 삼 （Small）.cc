#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll three(int num, int sum, int len)
{
    if(len == 1 && sum % 3 == 0) return 1;
    else if(len == 1) return 0;

    ll ans = 0;

    for(int i = 0; i <= 2; i++)
        ans += three(i, sum + i, len - 1);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1) cout << 0;
     
    else
    {
        ll ans = 0;

        for(int i = 1; i <= 2; i++)
             ans += three(i, i, n);
        
        cout << ans;
    }
    
    return 0;
}
