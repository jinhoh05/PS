#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
string bit, s;
map<string, char> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> bit >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        mp[s] = i + 65;
    }

    s = "";
    for(char c : bit){
        s += c;
        if(mp.find(s) != mp.end()){
            cout << mp[s];
            s = "";
        }
    }

    return 0;
}