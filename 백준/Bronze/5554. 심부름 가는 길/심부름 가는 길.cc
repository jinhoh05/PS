#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
int a, b;

string c;

int main()
{
    cin >> n >> m >> a >> b;
    cout << (n + m + a + b) / 60 << "\n" << (n + m + a + b) % 60;

    return 0;
}
