#include <bits/stdc++.h>

using namespace std;

int n, cnt = 1;
int arr[100005];
stack<int> stk;
vector<char> v;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=1;i<=n;i++){
        stk.push(i);
        v.push_back('+');

        while(!stk.empty() && stk.top() == arr[cnt]){
            stk.pop();
            v.push_back('-');
            cnt++;
        }
    }

    if(!stk.empty()) cout << "NO";

    else{
        for(char u : v) cout << u << "\n";
    }

    return 0;
}
