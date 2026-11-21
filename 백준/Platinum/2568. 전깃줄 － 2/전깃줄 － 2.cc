#include <bits/stdc++.h>

using namespace std;

int n, cnt, sum;
int DP[500005], vt[500005], path[500005], ans[500005];

struct st{
    int a, b;

    bool operator<(const st &t)const{
        return b < t.b;
    }
}elec[500005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> elec[i].a >> elec[i].b;

    sort(elec + 1, elec + n + 1);

    for(int i=1;i<=n;i++){
        int temp = lower_bound(&DP[0], &DP[cnt], elec[i].a) - &DP[0];

        if(cnt == temp){
            DP[cnt++] = elec[i].a;
            path[sum++] = cnt;
        }

        else{
            path[sum++] = temp + 1;
            DP[temp] = elec[i].a;
        }
    }

    cout << n - cnt << "\n";

    for(int i=n-1;i>=0;i--){
        if(path[i] == cnt){
            vt[elec[i+1].a] = 1;
            cnt--;
        }

        if(!cnt) break;
    }

    for(int i=1;i<=n;i++){
        if(!vt[elec[i].a]) ans[++cnt] = elec[i].a;
    }

    sort(ans + 1, ans + cnt + 1);

    for(int i=1;i<=cnt;i++) cout << ans[i] << "\n";

    return 0;
}
