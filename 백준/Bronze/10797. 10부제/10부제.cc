#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    int cnt = 0;

    for(int i = 1; i <= 5; i++){
        int a;
        cin >> a;

        if(a == n) cnt++;
    }

    cout << cnt;

    return 0;
}
