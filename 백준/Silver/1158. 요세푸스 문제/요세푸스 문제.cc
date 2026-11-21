#include <bits/stdc++.h>

using namespace std;

int n, k, cnt, go;
int arr[10005], ans[10005];

void yose(int x, int lev){
    if(lev == k){
        ans[++cnt] = arr[x];
        arr[x] = arr[arr[x]];
        go = x;
        return;
    }

    yose(arr[x], lev + 1);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for(int i=1;i<=n;i++) arr[i] = i + 1;

    arr[n] = 1, go = n;

    for(int i=1;i<=n;i++) yose(go, 1);

    cout << "<";
    for(int i=1;i<cnt;i++) cout << ans[i] << ", ";
    cout << ans[cnt] << ">";

    return 0;
}
