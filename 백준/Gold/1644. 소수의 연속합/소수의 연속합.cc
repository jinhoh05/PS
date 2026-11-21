#include <bits/stdc++.h>

using namespace std;

int n, ans;
vector<bool> prime;
vector<int> v;

void eratos(){
    for(int i=2;i*i<=n;i++){
        if(!prime[i]) continue;
        for(int j=i*2;j<=n;j+=i) prime[j] = false;
    }
}

void calc(){
    int val = 0, l = 0, r = 0;

    while(1){
        if(val >= n) val -= v[l++];

        else if(r == v.size()) break;

        else val += v[r++];

        if(val == n) ans++;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    prime.resize(n + 1, true);
    eratos();

    for(int i=2;i<=n;i++){
        if(prime[i]) v.push_back(i);
    }

    calc();

    cout << ans;

    return 0;
}
