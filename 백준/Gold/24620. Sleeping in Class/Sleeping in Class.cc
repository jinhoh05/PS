#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t, n, p, l, cnt, ans;

ll num[100005], hap[100005];


set<string> word;

int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    
    cin >> t;
    
    while(t--){
        ans=100001;
        memset(num, 0, sizeof(num));
        memset(hap, 0, sizeof(hap));
        vector<ll> v;
        cin >> n;
        for(int i=1; i<=n; i++){ 
            cin >> num[i];
            hap[i] = hap[i-1] + num[i];
        }
        
        
        for(int i=1; i <= sqrt(hap[n]); i++){
            if(hap[n] % i == 0){
                v.push_back(i);
                if(i != hap[n]/i) v.push_back(hap[n]/i);
            }
        }
        
        sort(v.begin(), v.end());
        
        //for(int i=0; i<=n; i++) cout << hap[i] << " ";
        //cout << endl;
        
        for(int u : v){
            int l=0, r=1, cnt=0;
            for(int i=1; i<=n; i++){
                //cout << hap[l] << " " << hap[r] << endl;
                if(hap[r] - hap[l] > u) break;
                
                else if(hap[r] - hap[l] == u){
                    l = r;
                    r++;
                    cnt++;
                }
                
                else r++;
            }
            
            if(l == n){
                ans=min(ans, n-cnt);
            }
        }
        
        if(ans == 100001) ans=0;
        cout << ans << endl;
    }
    
    
    return 0;
}


