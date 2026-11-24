#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, p;
ll a[500005], ans[500005];
ll sum;

priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);

    cin >> n >> p;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    pq.push(a[0]);
    sum += a[0];
    if(a[0] < p) ans[0] = -1;
    else ans[0] = 1;

    for(int i=1; i<n; i++){
        pq.push(a[i]);
        sum += a[i]; 

        if(sum < p){
            ans[i] = -1;
            continue;
        }
        while(!pq.empty()){
            ll sc = pq.top();
            if(sum - sc >= p){
                pq.pop();
                sum -= sc;
            }
            else break;
        }

        ans[i] = pq.size();
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}