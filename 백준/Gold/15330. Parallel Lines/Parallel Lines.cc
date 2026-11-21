#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define eps 1e-8

using namespace std;

int n, ans;
int vt[20], res[20];
int x[20], y[20];

double ccw(int a, int b)
{
    if(x[a] == x[b]) return -1.0 * INF;
    return 1.0 * (y[a] - y[b]) / (x[a] - x[b]);
}

void check()
{
    double arr[20];
    int p = 0, cnt = 0;

    for(int i = 0; i < n; i += 2)
    {
        arr[p++] = ccw(res[i], res[i + 1]);
    }

    for(int i = 0; i < p; i++)
    {
        for(int j = i + 1; j < p; j++)
        {
            if(arr[i] == arr[j]) cnt++;
        }
    }

    ans = max(ans, cnt);
}

void dfs(int val, int start)
{
    if(val == n / 2)
    {
        check();
        return;
    }

    for(int i = start; i <= n; i++)
    {
        if(!vt[i])
        {
            vt[i] = 1;
            res[val * 2] = i;

            for(int j = i + 1; j <= n; j++)
            {
                if(!vt[j])
                {
                    vt[j] = 1;
                    res[val * 2 + 1] = j;
                    dfs(val + 1, i + 1);
                    vt[j] = 0;
                }
            }

            vt[i] = 0;
            break;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);

    dfs(0, 1);

    printf("%d", ans);

    return 0;
}
