#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, h, cnt;
ll lev, ans;
ll w[100005];
stack<ll> stk;

int main()
{
    //freopen("input.txt", "r", stdin);

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while(1){
        memset(w, 0, sizeof(w));
        ans = 0;

        cin >> n;

        if(!n) break;

        for(int i=1;i<=n;i++){
            lev = 0;

            cin >> h;

            while(!stk.empty() && stk.top() >= h){
                lev += w[stk.size() - 1];
                ans = max(ans, stk.top() * lev);
                stk.pop();
            }

            w[stk.size()] = lev + 1;
            stk.push(h);
        }

        lev = 0;
        while(!stk.empty()){
            lev += w[stk.size() - 1];
            ans = max(ans, stk.top() * lev);
            stk.pop();
        }

        printf("%lld\n", ans);
    }

    return 0;
}
