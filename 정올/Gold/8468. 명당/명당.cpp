#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, k, ans;
int a[200005];

multiset<int> s;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int l = 0, r = 0; r < n; r++)
    {
        s.insert(a[r]);

        while (*s.rbegin() - *s.begin() > k)
        {
            s.erase(s.find(a[l++]));
        }
        
        ans = max(ans, r - l + 1);
    }

    cout << ans;

    return 0;
}