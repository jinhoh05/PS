#include <bits/stdc++.h>

using namespace std;

int s1 = 1e9, s2 = 1e9, a, b, c, d, e;
    
int main()
{
    cin >> a >> b >> c;
    
    cout << (long long)(a / c + (a % c > 0 ? 1 : 0)) * (b / c + (b % c > 0 ? 1 : 0));   

    return 0;
}   
