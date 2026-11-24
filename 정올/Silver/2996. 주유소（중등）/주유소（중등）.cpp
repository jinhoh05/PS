#include <bits/stdc++.h>

using namespace std;
int n;
long long sum,dist[100005],price[100005],d[100005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d",&dist[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&price[i]);
    }

    d[1] = price[1] * dist[1];
    sum = price[1];

    for(int i=2;i<=n;i++) {
        if(price[i] < sum) sum = price[i];
        d[i] = d[i-1] + sum * dist[i];
    }
    printf("%lld",d[n]);


    return 0;
}