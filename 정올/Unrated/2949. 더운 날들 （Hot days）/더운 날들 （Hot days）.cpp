#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int D, N;
int temp[205];
int DP[205][205];

struct S
{

    int s, e, cost;

}cloth[205];

int dynamic()
{
    for(int i = 0; i < D; i++)
        for(int j = 0; j < N; j++)
            DP[i][j] = -1;

    for(int i = 0; i < N; i++)
        if(cloth[i].s <= temp[0] && temp[0] <= cloth[i].e)
            DP[0][i] = 0;

    for(int i = 1; i < D; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(cloth[j].s <= temp[i] && temp[i] <= cloth[j].e)
            {
                int val = 0;

                for(int k = 0; k < N; k++)
                {
                    if(DP[i - 1][k] != -1)
                    {
                        int temp = DP[i - 1][k] + abs(cloth[k].cost - cloth[j].cost);

                        if(val < temp) val = temp;
                    }
                }

                DP[i][j] = val;
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < N; i++)
    {
        if(ans < DP[D - 1][i]) ans = DP[D - 1][i];
    }

    return ans;
}

void input()
{
    scanf("%d %d", &D, &N);

    for (int i = 0; i < D; i++)
    {
        scanf("%d", &temp[i]);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &cloth[i].s, &cloth[i].e, &cloth[i].cost);
    }
}

int main()
{
    input();

    printf("%d", dynamic());

    return 0;
}
