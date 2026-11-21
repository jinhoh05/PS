#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M;
int cnt = 1;
int vt[25][25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char board[25][25];

queue<pii> q;

void init()
{
    cnt = 1;
    
    memset(vt, 0, sizeof(vt));
}

void push(int x, int y)
{
    if(x < 1 || x > N || y < 1 || y > M) return;
    if(vt[x][y] || board[x][y] == '#') return;

    vt[x][y] = 1;
    cnt++;

    q.push({x, y});

}

void bfs()
{
    while(!q.empty())
    {
        pii t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) push(t.first + dx[i], t.second + dy[i]);
    }
}

void input()
{
    cin >> M >> N;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> board[i][j];

            if(board[i][j] == '@')
            {
                vt[i][j] = 1;
                q.push({i, j});
            }
        }
    }
}

int main()
{
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    while(1)
    {
        init();
        
        input();

        if(N == 0 && M == 0) break;
        
        bfs();

        printf("%d\n", cnt);
    }

    return 0;
}
