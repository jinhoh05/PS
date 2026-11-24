#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;

string s;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        
        string res(s.size(), ' ');

        int req = 0, ans = 0;
        for (int j = s.size() - 1; j >= 0; j--)
        {
            if ((req > 0 && s[j] == 'C') || req >= j + 1) 
            {
                res[j] = '(';
                req--;

                if (s[j] == 'U') ans++;
            } 
            
            else 
            {
                res[j] = ')';
                req++;

                if (s[j] == 'U') ans++;
                else ans += 2;
            }   
        }

        cout << ans << "\n";
        cout << res << "\n";
    }

    return 0;
}