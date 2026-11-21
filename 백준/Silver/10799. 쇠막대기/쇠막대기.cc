#include <bits/stdc++.h>

using namespace std;

int cnt, ans;
string s;

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
    
    cin >> s;

    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            cnt++;

            if(s[i + 1] == ')'){
                cnt--;
                i++;
                ans += cnt;
            }
        }

        else if(s[i] == ')'){
            ans++;
            cnt--;
        }
    }

    cout << ans;

    return 0;
}
