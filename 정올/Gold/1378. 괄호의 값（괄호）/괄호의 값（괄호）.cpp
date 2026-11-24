#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m = 1, ans = 0;

string s;
vector<int> v;
stack<char> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '(')
        {
            m *= 2;
            st.push(c);
        }

        else if (c == '[')
        {
            m *= 3;
            st.push(c);
        }

        if (c == ')')
        {   
            if (st.empty() || st.top() != '(')
            {
                ans = 0;
                break;
            }

            if (i > 0 && s[i - 1] == '(') ans += m;
            
            m /= 2;
            st.pop();
        }
        
        if (c == ']')
        {   
            if (st.empty() || st.top() != '[')
            {
                ans = 0;
                break;
            }
            
            if (i > 0 && s[i - 1] == '[') ans += m;
            m /= 3;

            st.pop();
        }
    }

    if (!st.empty()) ans = 0;

    cout << ans;

    return 0;
}