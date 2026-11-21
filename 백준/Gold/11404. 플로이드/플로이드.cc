#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, m;
bool vt[105][105];
int bus[105][105];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(bus[i][k] != INF && bus[k][j] != INF){
                    bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]);
                }
            }
        }
    }

}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bus[i][j] = INF;
        }
    }

    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(bus[a][b] > c) bus[a][b] = c;
    }

    floyd();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j || bus[i][j] == INF) cout << 0 << " ";
            else cout << bus[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
