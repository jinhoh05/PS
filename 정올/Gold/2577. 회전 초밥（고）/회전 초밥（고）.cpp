#include <bits/stdc++.h>

using namespace std;

int n, d, k, c;
int cnt, ans;
int used[3001], sushi[3000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> d >> k >> c;
    for(int i=0; i<n; i++){
        cin >> sushi[i];
    }

    for(int i=0; i<k; i++){
        if(!used[sushi[i]]) cnt++;
        used[sushi[i]]++;
    }

    ans = (!used[c]) ? cnt + 1 : cnt;

    for(int i=1; i<n; i++){
        used[sushi[i-1]]--;
        if(!used[sushi[i-1]]) cnt--;

        if(!used[sushi[(i + k - 1) % n]]) cnt++;
        used[sushi[(i + k - 1) % n]]++;
        
        if(!used[c]) ans = max(ans, cnt + 1);
        else ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}