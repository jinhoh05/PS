#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;

ll D, K, S, H;

string s;

int main(){

    cin >> n >> s;

    reverse(s.begin(), s.end());

    for(auto i : s){
        if(i == 'D') D += K;
        if(i == 'K') K += S;
        if(i == 'S') S += H;
        if(i == 'H') H++;
    }

    cout << D;

    return 0;
}
