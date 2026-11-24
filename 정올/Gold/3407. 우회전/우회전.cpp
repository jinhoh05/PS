#include <bits/stdc++.h>

using namespace std;

int N, M;
int road[105][105], vt[105][105][4][4];

int cross[4] = {3, 2, 0, 1};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct data{
    int x, y, lev, dir, before_dir;

    bool operator<(const data t)const{
        return lev > t.lev;
    }
};

priority_queue<data> q;

void push(int x, int y, int lev, int dir, int before_dir)
{
    if(x < 1 || x > N || y < 1 || y > M) return;
    if(vt[x][y][dir][before_dir]) return;
    if(road[x][y] == 'X') return;

    vt[x][y][dir][before_dir] = 1;

    q.push({x + dx[dir], y + dy[dir], lev + 1, dir, dir});
    if(before_dir == dir) q.push({x, y, lev, cross[dir], dir});
}

int bfs()
{
    while(!q.empty())
    {
        data t = q.top();
        q.pop();

        if(road[t.x][t.y] == 'B') return t.lev;

        push(t.x, t.y, t.lev, t.dir, t.before_dir);
    }

    return -1;
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            scanf(" %c", &road[i][j]);

            if(road[i][j] == 'A')
            {
                q.push({i, j, 0, 0, 0});
                q.push({i, j, 0, 1, 1});
                q.push({i, j, 0, 2, 2});
                q.push({i, j, 0, 3, 3});
            }
        }
    }

    printf("%d", bfs());

    return 0;
}