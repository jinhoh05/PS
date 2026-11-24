#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;

string s, b, ans;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> b;
    for (int i = 0; i < s.size(); i++)
    {
        ans += s[i];
        if (ans.size() >= b.size())
        {
            int cnt = 0, sz = ans.size();
            for (int j = 1; j <= b.size(); j++)
            {
                if(ans[sz - j] == b[b.size() - j]) cnt++;
            }
            if (cnt == b.size()) ans.erase(sz - b.size(), b.size());
        }
    }

    if (ans == "") cout << "FRULA";
    else cout << ans;

    return 0;
}