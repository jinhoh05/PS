#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, hap = 0, ans = 0;

    for(int i = 1; i <= 4; i++)
    {
        cin >> a >> b;

        hap = hap - a + b;

        ans = max(ans, hap);
    }

    cout << ans;

    return 0;
}
