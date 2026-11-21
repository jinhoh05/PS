#include <bits/stdc++.h>

using namespace std;

int n, m;
int obj[105][105];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        obj[a][b] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(obj[i][k] && obj[k][j]) obj[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(!obj[i][j] && !obj[j][i]) cnt++;
        }

        cout << cnt - 1 << "\n";
    }

    return 0;
}
