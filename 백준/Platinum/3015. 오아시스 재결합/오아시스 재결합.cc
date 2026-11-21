#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n;
ll ans;
stack<pii> stk;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=0;i<n;i++){
        int h;
        cin >> h;

        while(!stk.empty() && stk.top().first < h){
            ans += stk.top().second;
            stk.pop();
        }

        if(stk.empty()) stk.push({h, 1});

        else{
            if(stk.top().first == h){
                pii x = stk.top();
                stk.pop();

                ans += x.second;

                if(!stk.empty()) ans++;

                x.second++;
                stk.push(x);
            }

            else{
                stk.push({h, 1});
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
