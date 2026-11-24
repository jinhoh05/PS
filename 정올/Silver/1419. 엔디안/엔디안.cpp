#include <bits/stdc++.h>

using namespace std;
using ul=unsigned int;

ul n;

int main()
{
    cin >> n;

    ul a = n % 256;
    ul b = (n >> 8) % 256;
    ul c = (n >> 16) % 256;
    ul d = (n >> 24) % 256;

    cout << (a << 24) + (b << 16) + (c << 8) + (d);



    return 0;
}