#include <bits/stdc++.h>

using namespace std;
int n, k;
int DP[15];

void dynamic(){
    DP[1] = 1, DP[2] = 2, DP[3] = 4;

    for(int i=0;i<n;i++) {
        scanf("%d", &k);
        for(int j=4;j<=k;j++) {
            DP[j] = DP[j - 1] + DP[j - 2] + DP[j - 3];
        }
        printf("%d\n", DP[k]);
    }
}

int main()
{
    scanf("%d",&n);

    dynamic();

    return 0;
}
