#include <bits/stdc++.h>

using namespace std;

int t;
int a, b, c;

int main()
{
    cin >> t;

    a = t / 300;
    t %= 300;

    b = t / 60;
    t %= 60;

    c = t / 10;
    t %= 10;

    if(t) cout << -1;
    else cout << a << " " << b << " " << c;

    return 0;
}
