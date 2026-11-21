#include <bits/stdc++.h>

using namespace std;

int n, k, ans;
int student[5][5];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        if(b == 1 || b == 2) student[0][1]++;
        else if(b == 3 || b == 4) student[a][2]++;
        else student[a][3]++;
    }


    for(int i=0;i<2;i++){
        for(int j=1;j<=3;j++){
            ans += student[i][j] / k;
            if(student[i][j] % k != 0) ans++;
        }
    }

    cout << ans;

    return 0;
}
