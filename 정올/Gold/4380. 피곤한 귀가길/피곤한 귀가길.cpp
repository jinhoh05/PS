#include <bits/stdc++.h>

using namespace std;

int N, M, P, K;
int vt[1505][1505];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Data{

    int x, y, lev;

};

Data point[5005];

queue<Data> q;

void push(int x, int y, int lev)
{
    if(x < 1 || x > N || y < 1 || y > M) return;
    if(vt[x][y]) return;

    vt[x][y] = 1;

    q.push({x, y, lev + 1});
}

int bfs()
{
    if(vt[1][1] || vt[N][M]) return -1;

    q.push({1, 1, 0});

    while(!q.empty())
    {
        Data t = q.front();
        q.pop();

        if(t.x == N && t.y == M) return t.lev;

        for(int i = 0; i < 4; i++)
        {
            push(t.x + dx[i], t.y + dy[i], t.lev);
        }
    }

    return -1;
}

void Fill(int i)
{
    int x = point[i].x, y = point[i].y - K;

    bool flag = false;
    
    if(K == 0)
    {
        vt[x][y] = 1;
        return;
    }
    
    while(1)
    {
        if(x == point[i].x && y == point[i].y - K && flag == true) break;

        flag = true;

        if(x <= point[i].x && y < point[i].y)
        {
            if(1 <= x && x <= N && 1 <= y && y <= M) vt[x][y] = 1;
            x--, y++;
        }

        else if(x < point[i].x && y >= point[i].y)
        {
            if(1 <= x && x <= N && 1 <= y && y <= M) vt[x][y] = 1;
            x++, y++;
        }

        else if(x >= point[i].x && y > point[i].y)
        {
            if(1 <= x && x <= N && 1 <= y && y <= M) vt[x][y] = 1;
            x++, y--;
        }

        else if(x > point[i].x && y <= point[i].y)
        {
            if(1 <= x && x <= N && 1 <= y && y <= M) vt[x][y] = 1;
            x--, y--;
        }
    }
}

void input()
{
    scanf("%d %d", &M, &N);
    scanf("%d %d", &P, &K);

    for(int i = 1; i <= P; i++)
        scanf("%d %d", &point[i].y, &point[i].x);
}

int main()
{
    //freopen("output.txt", "w", stdout);

    input();

    for(int i = 1; i <= P; i++) Fill(i);

    for(int i = 1; i <= P; i++){
        int sx = abs(1 - point[i].x) + abs(1 - point[i].y);
        int ex = abs(N - point[i].x) + abs(M - point[i].y);

        if (sx <= K || ex <= K) {
            printf("-1");
            return 0;
        }
    }
    
    printf("%d", bfs());

    return 0;
}