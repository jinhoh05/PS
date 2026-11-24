#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans=200005;
int h;
int up[200005], down[200005];

vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        if(i % 2) cin >> up[i / 2];
        else cin >> down[i / 2];
    }

    int l = n / 2;
    if(n % 2) l += 1;
    sort(up, up+n/2);
    sort(down, down+l);

    int cnt=0;
    for(int i=1; i<=h; i++){
        int idx = lower_bound(down, down+l, i) - down;
        int k = l - idx;
        
        idx = lower_bound(up, up+n/2, h-i+1) - up;
        k += n/2 - idx;

        if(k < ans){
            ans = k;
            cnt = 1;
        }

        else if(k == ans) cnt++;
    }

    cout << ans << " " << cnt;

    return 0;
}