#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, s, cnt;
int arr[25];

void dfs(int x, int sum){
    if(x == n) return;
    if(sum + arr[x] == s) cnt++;

    dfs(x + 1, sum);
    dfs(x + 1, sum + arr[x]);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;

    for(int i=0;i<n;i++) cin >> arr[i];

    dfs(0, 0);

    cout << cnt;

    return 0;
}
