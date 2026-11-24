#include <bits/stdc++.h>

using namespace std;

bool vt[1000005], tr[1000005];

int N, M, c;
int V;

int group[1000005];
int arr[2][1005][1005];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

char board[1005][1005];

vector<int> see;
vector<int> G[1000005], R[1000005];


bool mv(int x, int y)
{
    return !(x < 0 || x >= N || y < 0 || y >= M || board[x][y] == '#');
}

void dfs1(int x)
{
    if(vt[x]) return;
    vt[x] = 1;

    for(auto& y : G[x]) dfs1(y);
    
    see.push_back(x);
}

void dfs2(int x)
{
    if(!vt[x]) return;
    vt[x] = 0;
	
    group[x] = V;

    for(auto& y : R[x]) dfs2(y);
}

void check()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == '.')
            {
                for(int k = 0; k < 2; k++)
                {
                    if(!mv(i + dx[k], j + dy[k])) arr[k][i][j] = ++c;
                    else arr[k][i][j] = arr[k][i + dx[k]][j + dy[k]];
                }
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == '.')
            {
                for(int k = 0; k < 2; k++)
                {
                    if(!mv(i + dx[k], j + dy[k]) || !mv(i + dx[k + 2], j + dy[k + 2]))
                    {
                        G[arr[k][i][j]].push_back(arr[!k][i][j]);
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf(" %c", &board[i][j]);
        }
    }

    check();

    for(int i = 1; i <= c; i++) dfs1(i);

    for(int i = 1; i <= c; i++)
    {
        for (auto& j : G[i])
        {
            R[j].push_back(i);
        }
    }

    while(!see.empty())
    {
	int x = see.back();

	if(vt[x])
	{
	    V++;	
	    dfs2(x);
	}

	see.pop_back();
    }

    for(int i = 1; i <= c; i++)
    {
	for(auto& j : G[i])
	{
	    if(group[i] + 1 == group[j]) tr[group[i]] = 1;
	}
    }

    bool flag = true;
    for(int i = 1; i < V; i++)
    {
    	if(!tr[i])
    	{
            flag = false;
            break;
        }
    }

    if(flag) printf("1");
    else printf("0");

    return 0;
}
