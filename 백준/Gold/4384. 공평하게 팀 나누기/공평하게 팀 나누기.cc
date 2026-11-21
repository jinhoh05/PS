#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, t;
int w[105];

ll dp[50005];

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //cin >> t;
    //while(t--){
        int sum=0, w1=0, w2=0, ans=INT_MAX;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> w[i];
            sum += w[i];
        }

        for(int i=0; i<n; i++){
            for(int j=sum/2; j>=w[i]; j--){
                dp[j] |= dp[j-w[i]] << 1;
            }
        }

        int i;
        if(n%2){
            for(i=sum/2; i>=0 && ((dp[i] & (1ll << (n/2))) == 0) && ((dp[i] & (1ll << (n/2+1))) == 0); i--);
        }
        else{
            for(i=sum/2; i>=0 && ((dp[i] & (1ll << (n/2))) == 0); i--);
        }

        cout << i << " " << sum - i << endl;
    //}

    return 0;
}
