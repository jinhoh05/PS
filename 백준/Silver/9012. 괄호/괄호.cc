#include <bits/stdc++.h>

using namespace std;

int t;

bool vps(string s) {
    stack<char> stk;

    bool flag = true;

    for(int i=0;i<s.size();i++){
        if(s[i] == '(') stk.push(s[i]);

        else if(!stk.empty() && s[i] == ')') stk.pop();

        else if(stk.empty() && s[i] == ')'){
            flag = false;
            break;
        }
    }

    if(stk.empty() && flag) return true;
    else return false;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> t;

    for(int i=1;i<=t;i++){
        string s;
        cin >> s;

        if(vps(s)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}
