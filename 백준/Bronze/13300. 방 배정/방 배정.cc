#include <bits/stdc++.h>

using namespace std;

int n, k, ans;
int student[10][10];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        student[a][b - 1]++;
    }


    for(int i=0;i<2;i++){
        for(int j=0;j<6;j++){
            ans += student[i][j] / k;
            if(student[i][j] % k != 0) ans++;
        }
    }

    cout << ans;

    return 0;
}
