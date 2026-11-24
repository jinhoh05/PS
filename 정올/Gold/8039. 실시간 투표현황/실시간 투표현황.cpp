#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, q, ans;

vector<int> v;
map<int, int> mp;
map<int, set<int>> mp2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        mp2[0].insert(i);
    }

    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b;

        if (!a)
        {
            cin >> c;
            
            mp2[mp[b]].erase(b);
            if (mp2[mp[b]].empty()) mp2.erase(mp[b]);

            mp[b] += c;
            mp2[mp[b]].insert(b);
        }

        else
        {
            auto it = mp2.find(b);
            if (it == mp2.end()) cout << "None";
            else
            {
                for (auto k : it->second)
                {
                    cout << k << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}