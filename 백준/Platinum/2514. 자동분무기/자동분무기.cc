#include <bits/stdc++.h>

using namespace std;

int m, n;
int gr_up[10], gr_down[10];
int up[10], down[10], n_up[10], n_down[10];
int farm[10][10], n_farm[10][10];
int ans[10][10], past[10][10];

void find_machine()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if((up[i] + down[j] - farm[i][j]) & 1)
            {
                ans[i][j] = 1;
                gr_up[i]++;
                gr_down[j]++;
            }
        }
    }
}

void new_farm()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            n_farm[i][j] = gr_up[i] + gr_down[j] - ans[i][j];
            n_up[i] += n_farm[i][j];
            n_down[j] += n_farm[i][j];
        }
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            int val1 = up[i] + down[j] - farm[i][j];
            int val2 = n_up[i] + n_down[j] - n_farm[i][j];

            if((val1 - val2) % 4) past[i][j] = 1;
        }
    }
}

void output()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(ans[i][j]) printf("%c ", past[i][j] ? '-' : '+');
            else printf(". ");
        }
        printf("\n");
    }
}

void input()
{
    scanf("%d %d", &m, &n);

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            scanf("%d", &farm[i][j]);

            farm[i][j] -= m;
            up[i] += farm[i][j];
            down[j] += farm[i][j];
        }
    }
}

int main()
{
    input();

    find_machine();

    new_farm();

    output();

    return 0;
}
