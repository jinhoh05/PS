#include <bits/stdc++.h>

using namespace std;

int N;
int honey[100005];
int l[100005], r[100005];

int calc()
{
    int ans = 0, val = 0;

    for(int i = 2; i < N; i++)
    {
        val = max(val, l[N] - l[i] - honey[i]);
    }

    ans = max(ans, val + r[1] - honey[1]);

    val = 0;

    for(int i = N - 1; i >= 2; i--)
    {
        val = max(val, r[1] - r[i] - honey[i]);
    }

    ans = max(ans, val + r[1] - honey[N]);

    val = 0;

    for(int i = 2; i < N; i++)
    {
        val = max(val, l[i] - r[i]);
    }

    ans = max(ans, val - honey[1] - honey[N]);

    return ans;
}

int main()
{
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &honey[i]);
        l[i] = l[i - 1] + honey[i];
    }

    int temp = l[N];

    for(int i = 1; i <= N; i++)
    {
        r[i] = temp;
        temp -= honey[i];
    }

    printf("%d", calc());

    return 0;
}