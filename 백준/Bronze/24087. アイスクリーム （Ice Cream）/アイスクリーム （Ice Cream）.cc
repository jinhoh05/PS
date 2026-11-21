#include<bits/stdc++.h>

using namespace std;

int main()
{
    int s, a, b;
    cin >> s >> a >> b;
    
    int val = s - a;
    
    if(val <= 0) cout << 250;
    else if(val % b > 0) cout << 250 + ((val / b) + 1) * 100;
    else cout << 250 + (val / b) * 100;
    
    return 0;
}