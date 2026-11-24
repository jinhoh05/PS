#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int T, N, M;
int dx[9] = {1, 1, 1, -1, -1, -1, 0, 0, 0};
int dy[9] = {0, -1, 1, 0, -1, 1, 1, -1, 0};
int place[9] = {3, 5, 4, 0, 2, 1, 7, 6, 8};

char wall[105][105];

int vt[105][105][10];

struct data{

    int fx, fy, hx, hy;

};

void push(queue<data> &q, int fx, int fy, int hx, int hy)
{
    /// 발이 움직일때
    for(int i = 0; i < 9; i++)
    {
        int nfx = hx + dx[i], nfy = hy + dy[i];

        if(nfx < 1 || nfy < 1 || nfx > N || nfy > M) continue;
        if(wall[nfx][nfy] != 'F' && wall[nfx][nfy] != 'B') continue;
        if(vt[hx][hy][i]) continue;
        if(nfx < hx) continue;

        vt[hx][hy][i] = 1;
        q.push({nfx, nfy, hx, hy});
    }

    /// 손이 움직일때
    for(int i = 0; i < 9; i++)
    {
        int nhx = fx + dx[i], nhy = fy + dy[i];

        if(nhx < 1 || nhy < 1 || nhx > N || nhy > M) continue;
        if(wall[nhx][nhy] != 'H' && wall[nhx][nhy] != 'B') continue;
        if(vt[nhx][nhy][place[i]]) continue;
        if(fx < nhx) continue;

        vt[nhx][nhy][place[i]] = 1;
        q.push({fx, fy, nhx, nhy});
    }
}

int bfs(int x, int y)
{
    queue<data> q;

    q.push({x, y, x, y});

    while(!q.empty())
    {
        data t = q.front();
        q.pop();

        if(t.fx == 1) return 1;

        push(q, t.fx, t.fy, t.hx, t.hy);
    }

    return 0;
}

int main()
{
    scanf("%d", &T);

    while(T--)
    {
        int x, y;

        scanf("%d %d", &N, &M);

        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                scanf(" %c", &wall[i][j]);

                if(wall[i][j] == '*')
                {
                    x = i;
                    y = j;
                }
            }
        }

        memset(vt, 0, sizeof(vt));

        if(bfs(x, y)) printf("Climbable\n");
        else printf("Not Climbable\n");
    }

    return 0;
}