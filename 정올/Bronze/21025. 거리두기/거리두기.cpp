#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans, k;
int a[105];

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if(v.empty()) v.push_back(a[i]);
        else v.push_back(min(v.back() - k, a[i]));
    }

    reverse(v.begin(), v.end());

    for (int u : v)
    {
        cout << u << " ";
    }

    return 0;
}