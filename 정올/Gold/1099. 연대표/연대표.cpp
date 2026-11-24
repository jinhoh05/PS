#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;

vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        erase(s1, '.');
        erase(s2, '.');

        int st = stoi(s1), ed = stoi(s2);
        v.push_back({st, ed});
    }

    sort(v.begin(), v.end());

    for (auto [st, ed] : v)
    {
        while (!pq.empty() && pq.top() <= st) pq.pop();
        pq.push(ed);
        ans = max(ans, (int)pq.size());
    }

    cout << ans;

    return 0;
}