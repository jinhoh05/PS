#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;
int dice[10];

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dice[x]++;
    }

    for (int i = 1; i <= 3; i++)
    {
        int up = dice[i];
        int down = dice[7 - i];

        if (up + down > 0) {
            ans += max(1, abs(up - down));
        }
    }

    cout << ans;

    return 0;
}