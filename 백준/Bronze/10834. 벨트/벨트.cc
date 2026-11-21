#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int m, ans = 1, rot = 1;

    cin >> m;

    for(int i=1;i<=m;i++){
        int a, b, s;
        cin >> a >> b >> s;
        ans = ans / a * b;
        rot = s ? !rot : rot;
    }

    if(rot) cout << "0 " << ans;
    else cout << "1 " << ans;

    return 0;
}
