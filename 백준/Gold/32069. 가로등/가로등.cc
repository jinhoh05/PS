#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k, cnt;

ll arr[300005];
ll l;

struct Data{
    
    ll x, lev;
    
    bool operator<(const Data&t)const{
        return lev > t.lev;
    }
};

priority_queue<Data> pq;

set<ll> st;

int main(){
    
    scanf("%lld %d %d", &l, &n, &k);
    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
        pq.push({arr[i], 0});
    }
    
    while(!pq.empty()){
        ll x = pq.top().x;
        ll lev = pq.top().lev;
        pq.pop();
        
        if(st.find(x) != st.end()) continue;
        st.insert(x);
        
        cnt++;

        printf("%lld\n", lev);
        
        if(x-1 >= 0) pq.push({x-1, lev+1});
        if(x+1 <= l) pq.push({x+1, lev+1});
        
        if(cnt == k){
            break;
        }
    }
    
    return 0;
}