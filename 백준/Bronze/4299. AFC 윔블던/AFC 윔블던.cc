#include <bits/stdc++.h>

using namespace std;

int x, y, a, b;
    
int main()
{
    cin >> x >> y;
    
    a = (x + y) / 2;
    b = (x - y) / 2;
    
    if((x + y) % 2 != 0 || (x - y) % 2 != 0) cout << -1;
    
    else
    {
        if(a >= 0 && b >= 0)
        {
            if(a >= b) cout << a << ' ' << b;
            else cout << b << ' ' << a;
        }
        
        else cout << -1;
    }
    
    return 0;
}
