#include <bits/stdc++.h>

using namespace std;

int n, ans;
int A[1005], lis[1005];

int main(int)
{
    scanf("%d", &n);

    for(int i=1;i<=n;i++) scanf("%d", &A[i]);

    for(int i=1;i<=n;i++){
        int small = 0;

        for(int j=0;j<i;j++){
            if(A[i] > A[j]){
                if(small < lis[j]) small = lis[j];
            }
        }

        lis[i] = small + 1;

        if(ans < lis[i]) ans = lis[i];
    }

    printf("%d", ans);

    return 0;

}
