#include <bits/stdc++.h>

using namespace std;

int ans;
int D1, D2;
int vt[2005][2005];

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> D1 >> D2;

    for(int i=D1;i<=D2;i++){
        for(int j=1;j<=i;j++){
            int g = gcd(i, j);

            if(vt[i / g][j / g] == 0){
                vt[i / g][j / g] = 1;
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
