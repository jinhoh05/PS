#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans[205][205], planet[205][205];

int main()
{
    scanf("%d %d", &N, &M);
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            scanf("%d", &planet[i][j]);
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            ans[i][j] = planet[i][j] + max(ans[i - 1][j], ans[i][j - 1]);
        }
    }
    
    printf("%d", ans[N][M]);
    
    return 0;
}