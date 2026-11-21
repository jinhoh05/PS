#include<bits/stdc++.h>
#include "supertrees.h"

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll G[1000005];
ll grp[1000005];

vector<ll> bri[1000005];
vector<pll> edg, v[105];

ll find_p(ll x){
    if(x==G[x]) return x;
    return G[x]=find_p(G[x]);
}

void union_find(ll a, ll b){
    a=find_p(a);
    b=find_p(b);

    if(a==b) return;
    G[b]=a;
}

int construct(vector<vector<int>> p) {
    ll n = p.size();

    for(ll i=0;i<=n;i++) G[i]=i;

    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            v[p[i][j]].push_back({i, j});
        }
    }

    if(v[3].size()) return 0;

    for(pll k:v[1]) union_find(k.first, k.second);
    for(pll k:v[2]) union_find(k.first, k.second);
    for(pll k:v[0]) if(find_p(k.first)==find_p(k.second)) return 0;

    ll cnt=0;
    for(ll i=0;i<n;i++){
        if(grp[find_p(i)]==0){
            cnt++;
            grp[find_p(i)]=cnt;
            bri[cnt].push_back(i);
        }

        else bri[grp[find_p(i)]].push_back(i);
    }

    for(ll u=1; u<=cnt; u++){
        ll sz=bri[u].size();
        for(ll k:bri[u]) G[k]=k;

        vector<ll> brd;
        for(ll i=0; i<sz; i++){
            ll k=bri[u][i];

            for(ll j=i+1; j<sz; j++){
                ll l=bri[u][j];

                if(p[k][l]==1){
                    if(find_p(k) != find_p(l)) edg.push_back({k,l});
                    union_find(k,l);
                }
            }
        }

        for(ll i=0; i<sz; i++){
            ll k=bri[u][i];

            for(ll j=i+1;j<sz;j++){
                ll l=bri[u][j];
                if(p[k][l]==2 && find_p(k)==find_p(l)) return 0;
            }
        }

        for(ll k:bri[u]){
            if(G[k]==k) brd.push_back(k);
        }

        ll sz2 = brd.size();
        if(sz2==2) return 0;
        for(ll i=0; i<sz2; i++) edg.push_back({brd[i], brd[(i+1)%sz2]});
    }

    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        vector<int> k;
        k.resize(n);
        ans.push_back(k);
    }

    for(pair<ll, ll> k:edg){
        if(k.first != k.second){
            ans[k.first][k.second]=1;
            ans[k.second][k.first]=1;
       }
    }

    build(ans);

    return 1;
}
