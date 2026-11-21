#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, h, cnt;
ll lev, ans;
ll w[100005];
stack<ll> stk;

void calc(){
    lev = 0;

    while(!stk.empty()){
        lev += w[stk.size() - 1];
        ans = max(ans, stk.top() * lev);
        stk.pop();
    }
}

void push(){
    while(!stk.empty() && stk.top() >= h){
        lev += w[stk.size() - 1];
        ans = max(ans, stk.top() * lev);
        stk.pop();
    }

    w[stk.size()] = lev + 1;
    stk.push(h);
}

int main()
{
    //freopen("input.txt", "r", stdin);

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i=1;i<=n;i++){
        lev = 0;

        cin >> h;

        push();
    }

    calc();

    printf("%lld\n", ans);

    return 0;
}
