#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;

int main(){
    cin >> t;
    while(t--){
        ll student, totalCandy = 0, candy;
        cin >> student;
        for(int i = 0; i < student; i++) {
            cin >> candy;
            totalCandy = (totalCandy + candy) % student;
        }
        if(totalCandy % student) cout << "NO\n";
        else cout << "YES\n";
    }
    
    return 0;
}