#include <bits/stdc++.h>
using namespace std;

int n, k1, k2;
int p[3005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k1 >> k2;
    for(int i=0; i<n; i++){
        cin >> p[i];
    }

    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(i == j) continue;
            if(p[i] == p[j] && abs(i - j) <= k1) cnt++;
            if(p[i] != p[j] && abs(i - j) <= k2) cnt++;
        }
        cout << cnt << " ";
    }


}