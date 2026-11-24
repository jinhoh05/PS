#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int r, c;
int ans[15][15];
int vt[15][15];
int cnt[3];

char l[3] = {'A', 'B', 'C'};
int board[15][15];

vector<int> v;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool check(int x, int y, int lev, int pre)
{
    if (x < 1 || x > r || y < 1 || y > c) return false;
    if (vt[x][y]) return false;
    
    return board[x][y] == (pre + 1) % 3;
}

int dfs(int x, int y, int lev)
{
    if (lev == r * c) return true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny, lev + 1, board[x][y]))
        {
            vt[nx][ny] = lev + 1;
            if (dfs(nx, ny, lev + 1)) return true;
            vt[nx][ny] = 0;
        }
    }

    return false;
}

bool preprocess()
{
    sort(cnt, cnt + 3);

    int q = r * c / 3;
    int rem = r * c % 3;

    for (int i = 0; i < 3; i++)
    {
        int ex = q + (i >= 3 - rem);

        if (cnt[i] != ex)
        {
            cout << "impossible\n";
            return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            char x;
            cin >> x;

            board[i][j] = x - 'A';
            cnt[board[i][j]]++;
        }
    }

    if(!preprocess()) return 0;

    int flag = 0;
    for (int i = 1; i <= r && !flag; i++)
    {
        for (int j = 1; j <= c && !flag; j++)
        {
            if (i != 1 && i != r && j != 1 && j != c) continue;
            vt[i][j] = 1;

            if (dfs(i, j, 1)) flag = true;
            else vt[i][j] = 0;
        }
    }

    if (!flag) cout << "impossible";    
    else
    {
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                cout << vt[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}