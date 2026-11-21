#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, ans = 0;

    cin >> n;

    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        ans += b % a;
    }

    cout << ans;

    return 0;
}
