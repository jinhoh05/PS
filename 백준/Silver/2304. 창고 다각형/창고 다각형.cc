#include <bits/stdc++.h>

using namespace std;

int n, k, len, ans;
int l = 1005, r, longest;
int arr[1005];

stack<int> stk;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    while(n--){
        cin >> k >> len;
        arr[k] = len;
        if(r < k) r = k;
        if(l > k) l = k;
        if(len > arr[longest]) longest = k;
    }

    for(int i=l;i<=longest;i++){
        if(arr[i]){
            if(stk.empty() || arr[i] > stk.top()) stk.push(arr[i]);
        }

        ans += stk.top();
    }

    while(!stk.empty()) stk.pop();

    for(int i=r;i>longest;i--){
        if(arr[i]){
            if(stk.empty() || arr[i] > stk.top()) stk.push(arr[i]);
        }
        ans += stk.top();
    }

    cout << ans;

    return 0;
}
