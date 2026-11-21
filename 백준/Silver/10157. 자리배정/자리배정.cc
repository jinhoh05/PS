#include <bits/stdc++.h>

using namespace std;

int d = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int c, r, k, cnt = 1, x, y;

    cin >> c >> r >> k;

    if(k > c * r) cout << 0;

    else{
        vector<vector<int>> v(r, vector<int>(c, 0));

        y = r - 1, x = 0;

        while(cnt < k){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx < 0 || nx >= c || ny < 0 || ny >= r || v[ny][nx] != 0){
                d = (d + 1) % 4;
                continue;
            }

            v[y][x] = cnt++;
            y = ny, x = nx;
        }

        cout << x + 1 << ' ' << r - y;
    }

    return 0;
}
