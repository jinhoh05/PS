#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int A[1000005], p[1000005];
vector<int> lis, ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> A[i];

    lis.push_back(A[1]);

    for(int i=2;i<=n;i++){
        if(lis[cnt] < A[i]){
            lis.push_back(A[i]);
            p[i] = ++cnt;
        }

        else{
            int temp = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
            lis[temp] = A[i];
            p[i] = temp;
        }
    }

    cout << cnt + 1 << "\n";

    for(int i=n;i>=1;i--){
        if(p[i] == cnt){
            ans.push_back(A[i]);
            cnt--;
        }

        if(cnt < 0) break;
    }

    reverse(ans.begin(), ans.end());

    for(int u : ans) cout << u << " ";

    return 0;
}
