#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int n, m, ans1, ans2, mx = -1e9;
int x[MAX * 2], y[MAX * 2];

struct st{
    int a, b;
    bool operator<(const st &t)const{
        return a < t.a;
    }
}arr[MAX];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i];
        x[n + i] = x[i];
        y[n + i] = y[i];
    }

    for(int i=1;i<=n;i++){
        if(y[i] >= 0) continue;

        int state = 0, last = 0;

        for(int j=0;j<n;j++){
            int s = i + j, e = s < 2 * n ? s + 1 : 1;
            if(x[s] == x[e] && (long long)y[s] * y[e] < 0){
                if(state) arr[++m] = {min(last, x[s]), max(last, x[s])};
                else last = x[s];
                state ^= 1;
            }
        }

        break;
    }

    sort(arr + 1, arr + m + 1);

    for(int i=1;i<=m;i++){
        if(mx < arr[i].a) ans1++;
        mx = max(mx, arr[i].b);
        if(i == m || arr[i + 1].a > arr[i].b) ans2++;
    }

    cout << ans1 << " " << ans2;

    return 0;
}
