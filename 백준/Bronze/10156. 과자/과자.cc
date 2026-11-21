#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int k, n, m;

    cin >> k >> n >> m;

    int num = k * n;

    if(num <= 0 || m >= num) cout << 0;
    else cout << num - m;

    return 0;
}
