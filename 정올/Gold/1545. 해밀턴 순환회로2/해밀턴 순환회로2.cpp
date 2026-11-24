/**
    DP[i][j] = i를 비트로 볼때 1인 비트를 방문하였는데 j위치를 마지막으로 방문하였을때 최소비용
*/

#include <bits/stdc++.h>

using namespace std;

/// __builtin_popcount()

int n, ans;
int DP[1 << 20][20];
int table[20][20];

void init()
{
    for(int i = 0; i < (1 << n); i++)
        for(int j = 0; j < n; j++)
            DP[i][j] = 1e9;

    DP[0][0] = 0;
}

int dynamic()
{
    for(int i = 0; i < (1 << n); i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if((i & (1 << k)) == 0)
                {
                    int temp = DP[i][j] + table[j][k];

                    if(DP[i | (1 << k)][k] > temp) DP[i | (1 << k)][k] = temp;
                }
            }
        }
    }

    return DP[(1 << n) - 1][0];
}

void input()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &table[i][j]);

            if(!table[i][j]) table[i][j] = 1e9;
        }
    }
}

int main()
{
    input();

    init();

    printf("%d", dynamic());

    return 0;
}