#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100005];

long long ans;

map<int, int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    mp[0] = 1;

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
        ans += mp[arr[i]];
        mp[arr[i]]++;
    }

    cout << ans;

    return 0;
}