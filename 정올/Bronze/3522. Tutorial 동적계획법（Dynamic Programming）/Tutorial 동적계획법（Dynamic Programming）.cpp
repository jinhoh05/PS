#include <bits/stdc++.h>

using namespace std;
using ull=unsigned long long;
int n;
ull fibo[100005];
int main()
{
    scanf("%d",&n);

    fibo[1]=fibo[2]=1;
    if(n == 1 || n == 2){
        printf("1");
        return 0;
    }

    for(int i=3;i<=n;i++){
        fibo[i]=(fibo[i-2] + fibo[i-1]) % 1000000007;
       // printf("%lld\n",fibo[i]);
    }
    printf("%llu",fibo[n]);

    return 0;
}