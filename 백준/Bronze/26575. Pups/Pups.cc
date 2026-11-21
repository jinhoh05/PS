#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << fixed;
    cout.precision(2);
    
    int n; 
    cin >> n;
    
    for(int i=0; i<n; i++){
        double d, f, p; 
        cin >> d >> f >> p;
    
        double cost = d * f * p;
        cout << "$" << cost << "\n";
    }
    
    return 0;
}