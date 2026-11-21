#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;

ll sum;

struct Data{
    int t, s, idx;

    bool operator<(const Data &T)const{
        return s > T.s;
    }
}pr[105];


int main()
{
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        sum += a;
    }
    for(int i=1; i<=m; i++){
        int a;
        cin >> a;
        sum += a;
    }

    cout << sum;

    return 0;
}
