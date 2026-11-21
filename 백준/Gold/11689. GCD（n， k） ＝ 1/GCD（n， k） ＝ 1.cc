#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
ll n, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
    
    ans = n;
    
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans -= ans / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) {
        ans -= ans / n;
    }
    
    cout << ans;
    
    return 0;
}