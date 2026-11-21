#include <bits/stdc++.h>

using namespace std;

int n, ans;
int a[100005], a_idx[100005], b[100005], mv[100005];

int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    
    cin >> n;
    for(int i=0; i<n; i++){ 
        cin >> a[i];
        a_idx[a[i]] = i;
    }
    for(int i=0; i<n; i++) cin >> b[i];
    
    int idx=0;
    for(int i=0; i<n; i++){
        while(mv[idx]) idx++;
        
        if(b[i] == a[idx]) idx++;
        else{
            mv[a_idx[b[i]]]=1;
            ans++;
        }    
    }
    
    cout << ans;
    
    return 0;
}