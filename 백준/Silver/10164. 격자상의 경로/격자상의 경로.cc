#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int dfs(int x, int y){
    int grid[25][25];

    memset(grid, 0, sizeof(grid));

    grid[1][1] = 1;

    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            grid[i][j + 1] += grid[i][j];
            grid[i + 1][j] += grid[i][j];
        }
    }

    return grid[x][y];
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    if(k == 0) cout << dfs(n, m);

    else{
        int x = (k - 1) / m + 1;
        int y = (k - 1) % m + 1;
        cout << dfs(x, y) * dfs(n - x + 1, m - y + 1);
    }

    return 0;
}
