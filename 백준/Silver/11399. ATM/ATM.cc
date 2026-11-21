#include <bits/stdc++.h>

using namespace std;

int n, ans;
int greedy[1005];

int main(int)
{
    scanf("%d", &n);

    for(int i=1;i<=n;i++) scanf("%d", &greedy[i]);

    sort(greedy, greedy + n + 1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            ans += greedy[j];
        }
    }

    printf("%d", ans);

    return 0;

}
