#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;

int binary(int l, int r){
    int sum, mid = (l + r) / 2;

    while(r >= l){
        sum = 0;

        for(int u : v) sum += (u > mid) ? mid : u;

        if(sum == m) return mid;

        if(sum > m) r = mid - 1;
        else l = mid + 1;

        mid = (l + r) / 2;
    }

    return mid;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    v.resize(n);

    int h = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(v[i] > h) h = v[i];
    }

    cin >> m;

    cout << binary(0, h);

    return 0;
}
