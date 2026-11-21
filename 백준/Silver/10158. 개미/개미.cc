#include <bits/stdc++.h>

using namespace std;

int x, y;
int sx, sy;
int fx, fy;
int t;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> x >> y >> sx >> sy >> t;

    fx = (sx + t) % (x * 2);

    if(fx > x) fx = x * 2 - fx;

    fy = (sy + t) % (y * 2);
    if(fy > y) fy = y * 2 - fy;

    cout << fx << " " << fy;

    return 0;
}
