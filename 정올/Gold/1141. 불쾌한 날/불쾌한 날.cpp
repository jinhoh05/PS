#include <cstdio>
using ull = unsigned long long;
ull a[80001],mmo[80001];
ull n;
ull cnt;
ull sum;

int main(){

    scanf("%llu",&n);

    for(int i=0;i<n;i++){
        scanf("%llu",&a[i]);
    }

    for(int i=0;i<n;i++){
        while(cnt > 0 && mmo[cnt-1] <= a[i])
            mmo[--cnt]=0;
        sum+=cnt;
        mmo[cnt++]=a[i];
    }

    printf("%llu",sum);

    return 0;
}