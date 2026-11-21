#include "molecules.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, l, u, i, hap;

pair<int, int> W[200005];

vector<int> v, res;

std::vector<int> find_subset(int l, int u, std::vector<int> w) {
    n = w.size();
    
    for(int i=0; i<n; i++){
        W[i] = make_pair(w[i], i);
    }

    sort(W, W + n);

    ll sum1=0, sum2=0, i, j;
    for(i=n-1; i>=0; i--){
        sum1 += W[i].first;

        v.push_back(W[i].second);

        if(sum1 >= l && sum1 <= u){
            for(j=i; j<n; j++) res.push_back(W[j].second);
            return res;
        }

        if(sum1 > u) break;
    }

    for(j=0; j<n-i; j++){
        sum2 += W[j].first;

        if(W[j].first >= l && W[j].first <= u){
            for(int k=0; k<=j; k++) res.push_back(W[k].second);
            return res;
        }
    }

    if(sum2 <= u){
        for(int k=0; k<=j; k++){
            sum1 = sum1 - W[n-k-1].first + W[k].first;
            v[k] = W[k].second;

            if(sum1 >= l && sum1 <= u) return v;
        }
    }
    
    return std::vector<int>(0);
}
