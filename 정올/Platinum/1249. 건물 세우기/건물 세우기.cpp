#include <bits/stdc++.h>

using namespace std;

/// __builtin_popcount()

const int MAX = 1 << 20;

int n, ans;
int table[25][25];

struct data{
	int cost, path, idx;

};

data DP[MAX];

int dynamic()
{
    for(int i = 1; i < (1 << n); i++)
	{
        int bit = __builtin_popcount(i);
		DP[i].cost = INT_MAX;

        for(int j = 0; j < n; j++)
		{
			if(i & (1 << j))
			{
				int temp = DP[i ^ (1 << j)].cost + table[bit][j];

				if(DP[i].cost > temp)
				{
					DP[i].cost = temp;
					DP[i].path = i ^ (1 << j);
					DP[i].idx = j + 1;
				}
			}
        }
    }

	return DP[(1 << n) - 1].cost;
}

void path(int bit)
{
	if(bit <= 0) return;
	path(DP[bit].path);
	printf("%d ", DP[bit].idx);
}

void input()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &table[i][j]);
}

int main()
{
    input();

    printf("%d\n", dynamic());

    path((1 << n) - 1);

    return 0;
}