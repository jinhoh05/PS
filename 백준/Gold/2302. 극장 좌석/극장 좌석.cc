#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
int seat[50], fibo[50];
long long ans = 1;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=1;i<=m;i++){
        int x;
        cin >> x;
        seat[x] = 1;
    }

    fibo[0] = fibo[1] = 1;

    for(int i=2;i<=n;i++) fibo[i] = fibo[i - 1] + fibo[i - 2];

    for(int i=1;i<=n;i++){
        if(seat[i] == 0) cnt++;
        else{
            ans *= fibo[cnt];
            cnt = 0;
        }
    }

    cout << ans * (long long)fibo[cnt];

    return 0;
}
