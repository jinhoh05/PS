#include <bits/stdc++.h>

using ull = unsigned long long;
using namespace std;

ull a=1,b=0,c=0,d=0,res=0;

ull calc(ull x){
    ull a1=a,b1=b,c1=c,d1=d;

    if(x == 0) return 0;

    if(x % 2 == 0){
        calc(x/2);
        a1=a,b1=b,c1=c,d1=d;
        a=(a1*a1) + (b1*c1);
        b=c=(a1*b1) + (b1*d1);
        d=(c1*b1)+(d1*d1);
        a%=10000;
        b%=10000;
        c%=10000;
        d%=10000;
    }

    else if(x % 2 == 1){
        calc(x-1);
        a1=a,b1=b,c1=c,d1=d;
        a=a1 + b1;
        b=c=a1;
        d=c1;
        a%=10000;
        b%=10000;
        c%=10000;
        d%=10000;
    }


    return b;
}

int main()
{
    ull x,cnt=1;

    while(1){
        a=res=1;
        b=c=d=0;

        scanf("%llu",&x);

        if(x == -1) return 0;

        res=calc(x);

        printf("%llu\n",res);

    }

    return 0;
}