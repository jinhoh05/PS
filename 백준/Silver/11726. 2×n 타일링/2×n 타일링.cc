#include <bits/stdc++.h>

using namespace std;
int n,DP[1005];

int dynamic(){
    DP[1] = 1;
    DP[2] = 2;

    for(int i=3;i<=n;i++){
        DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
    }

    return DP[n];
}

int main()
{
    scanf("%d",&n);

    printf("%d",dynamic());

    return 0;
}
