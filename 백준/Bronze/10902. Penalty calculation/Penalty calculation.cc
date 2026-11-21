#include <bits/stdc++.h>

using namespace std;

int n;

struct Data{
    int t, s, idx;

    bool operator<(const Data &T)const{
        return s > T.s;
    }
}pr[105];


int main()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> pr[i].t >> pr[i].s;
        pr[i].idx = i;
    }

    sort(pr+1, pr+n+1);

    int p=1e9;
    pr[0]=pr[1];
    for(int i=1; i<=n; i++){
        if(pr[i].s != pr[i-1].s) break;
        if(pr[i].s == 0) p = 0;
        p = min(p, pr[i].t + (pr[i].idx - 1) * 20);
    }

    cout << p;

    return 0;
}
