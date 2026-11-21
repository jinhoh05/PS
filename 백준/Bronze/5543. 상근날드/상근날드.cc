#include <bits/stdc++.h>

using namespace std;

int s1 = 1e9, s2 = 1e9, a, b, c, d, e;
    
int main()
{
    cin >> a >> b >> c >> d >> e;
    
    cout << min({a, b, c}) + min(d, e) - 50;
    
    return 0;
}   
