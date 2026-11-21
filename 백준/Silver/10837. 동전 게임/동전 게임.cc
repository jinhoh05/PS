#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int k, c;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> k >> c;

    for(int i=1;i<=c;i++){
        int a, b;
        cin >> a >> b;

        int round = k - max(a, b);

        if((a >= b && a - round - b > 2) || a < b && b - round - a > 1) cout << "0\n";
        else cout << "1\n";
    }

    return 0;
}
