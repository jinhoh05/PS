#include <iostream>

using namespace std;

int board[10][10];
int ans[10][10];

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {-1, 1, -1, 0, 1, -1, 0, 1};

bool push(int x, int y, int dir)
{
    if(x < 1 || x > 8 || y < 1 || y > 8) return false;
    if(board[x][y] == 0) return false;
    if(board[x][y] == 1 && board[x - dx[dir]][y - dy[dir]] == 0) return false;

    if(board[x][y] == 1) return true;

    return push(x + dx[dir], y + dy[dir], dir);
}

int main()
{
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            if(board[i][j] == 0)
            {
                for(int k = 0; k < 8; k++)
                {
                    if(push(i + dx[k], j + dy[k], k))
                    {
                        ans[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }


    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}