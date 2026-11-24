#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M, T;

int wall[505][505], led[105][5], seq[1005];
int loc[505][505], vt[505][505];
int dist[105][105];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct data
{
    int x, y, d;
};

int DP[1005];

vector<pii> v[1005];

queue<data> q;

void push(int x, int y, int d, int i)
{
    if((x != 0 && y != 0) || (x != N && y != N + 1)){
        if(x < 1 || y < 1 || x > N || y > N) return;
    }

    if(vt[x][y] == i) return;

    if(loc[x][y]) dist[i][loc[x][y]] = dist[loc[x][y]][i] = d;
    vt[x][y] = i;

    q.push({x, y, d});
}

void bfs(int i)
{
    q.push({led[i][1], led[i][2], 0});

    while(!q.empty())
    {
        data t = q.front();
        q.pop();

        for(int j = 0; j < 4; j++)
        {
            int bit = wall[t.x][t.y];
            if(bit & (1 << j)) continue;

            push(t.x + dx[j], t.y + dy[j], t.d + 1, i);
        }
    }
}

void init()
{
    memset(vt, -1, sizeof(vt));

    led[1][1] = 1;
    led[M][1] = N, led[M][2] = N + 1, led[M][3] = N * N + 1;

    loc[N][N + 1] = M;
    
    seq[++T] = N * N + 1;
    
    v[0].push_back({1, 0});

    for(int i = 1; i <= T; i++) DP[i] = 1e9;

    for(int i = 1; i <= M; i++) bfs(i);    
}

int dynamic()
{
    for(int i = 1; i <= T; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(seq[i] == led[j][3])
            {
                v[i].push_back({0, 1e9});

                for(pii k : v[i - 1])
                {
                    DP[i] = min(DP[i], k.second + dist[j][k.first]);

                    if(v[i].back().second > k.second + dist[j][k.first])
                        v[i].back() = make_pair(j, k.second + dist[j][k.first]);
                }
            }
        }
    }

    return DP[T];
}

void input()
{
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            scanf("%d", &wall[i][j]);

    scanf("%d", &M);

    M += 2;

    for(int i = 2; i < M; i++)
    {
        scanf("%d %d %d", &led[i][1], &led[i][2], &led[i][3]);
        loc[led[i][1]][led[i][2]] = i;
    }

    scanf("%d", &T);

    for(int i = 1; i <= T; i++)
        scanf("%d", &seq[i]);
}

int main()
{
    input();

    init();

    printf("%d", dynamic());

    return 0;
}