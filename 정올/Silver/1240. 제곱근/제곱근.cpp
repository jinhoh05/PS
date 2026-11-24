#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    unsigned long long int n,st,ed,mid;
    scanf("%lld",&n);
    st=1;
    ed=( (unsigned long long)1 << 32)-1;


    while(st <= ed){
        mid=(st+ed)/2;

        if(mid * mid <= n && n < (mid+1) * (mid+1)){
            printf("%lld",mid);
            return 0;
        }

        if(mid*mid > n) ed=mid-1;
        else if((mid+1) * (mid+1) <= n) st=mid+1;
    }



    return 0;
}