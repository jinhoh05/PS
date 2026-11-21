#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int H, W;
bool adjacent[1<<11][1<<11];

ll dp[13][1<<11];
ll ans[13][13] = {0};

bool AdjacentCheck(unsigned int a, unsigned int b)
{
    if ((a & b) != 0) return false;

    unsigned int ab = a | b;
    for (int i = 0; i < W; ) {
        if (ab & (1<<i)) ++i;
        else {
            if (i == W-1 || (ab & (1<<(i+1))) != 0) return false;
            else i+=2;
        }
    }
    
    return true;
}

int main()
{
    while (scanf("%d %d", &H, &W) && (H || W)) {
        if (ans[H][W]) {printf("%lld\n", ans[H][W]); continue;}

        if (H < W) {int tmp = H; H = W; W = tmp;}   // make W small

        memset(dp, 0, sizeof(dp));
        memset(adjacent, 0, sizeof(adjacent));

        for (unsigned int i = 0; i < (1<<W); ++i)
            for (unsigned int j = 0; j < (1<<W); ++j)
                if (AdjacentCheck(i, j)) adjacent[i][j] = true;

        dp[0][0] = 1;
        for (int row = 0; row < H; ++row)
            for (unsigned int i = 0; i < (1<<W); ++i)
                for (unsigned int j = 0; j < (1<<W); ++j)
                    if (adjacent[i][j]) dp[row+1][j] += dp[row][i];

        printf("%lld\n", dp[H][0]);
        ans[H][W] = ans[W][H] = dp[H][0];
    }
    
    return 0;
}
