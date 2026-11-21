#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {

    cin >> n >> k;

    string s = "";

    for(int i=0; i<n-k; i++){
        s += 'a';
    }

    for(int i=n-k, cnt=0; i<n; i++){
        s += 'a'+cnt;
        cnt++;
    }

    cout << s;
   
    return 0;
}
