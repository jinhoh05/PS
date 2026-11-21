#include <bits/stdc++.h>

using namespace std;

int n;
int x[55], y[55];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> x[i] >> y[i];

    for(int i=1;i<=n;i++){
        int k = 1;
        for(int j=1;j<=n;j++){
            if(x[i] < x[j] && y[i] < y[j]) k++;
        }
        cout << k << " ";
    }

    return 0;
}
