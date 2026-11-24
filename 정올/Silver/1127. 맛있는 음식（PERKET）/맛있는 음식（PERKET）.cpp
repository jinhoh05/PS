#include <bits/stdc++.h>

using namespace std;

int N;
int ans = INT_MAX;
int S[15], B[15];

void dfs(int multiple, int prefix, int x)
{
    if(multiple != 1 && prefix != 0)
    {
        ans = min(ans, abs(multiple - prefix));
    }

    for(int i = x; i <= N; i++)
    {
        dfs(multiple, prefix, i + 1);
        dfs(multiple * S[i], prefix + B[i], i + 1);
    }
}

int main()
{
    scanf("%d", &N);

    for(int i = 1; i <= N; i++) scanf("%d %d", &S[i], &B[i]);

    dfs(1, 0, 1);

    printf("%d", ans);

    return 0;
}