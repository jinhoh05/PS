#include <bits/stdc++.h>

using namespace std;

int n;
int DP[10005];

struct st{
    int x, y;

    bool operator<(const st &t)const{
        return x < t.x;
    }

}build[10005];

int solve(int k){
    if(DP[k]) return DP[k];
    if(k <= 1) return DP[k] = abs(2 * build[k].y);

    int ans = 1e9, MAX = 0;

    for(int i=k-1;i>=0;i--){
        MAX = max(MAX, abs(build[i + 1].y));
        ans = min(ans, solve(i) + max(2 * MAX, build[k].x - build[i + 1].x));
    }

    return DP[k] = ans;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> build[i].x >> build[i].y;

    sort(build + 1, build + n + 1);

    cout << solve(n);

    return 0;
}
