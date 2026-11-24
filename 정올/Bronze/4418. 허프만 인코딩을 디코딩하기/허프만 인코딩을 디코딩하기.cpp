#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
string s, huf;
map<string, char> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        char ch;
        cin >> ch >> s;
        mp[s] = ch;
    }
    cin >> huf;

    s = "";
    for(char c : huf){
        s += c;
        if(mp.find(s) != mp.end()){
            cout << mp[s];
            s = "";
        }
    }

    return 0;
}