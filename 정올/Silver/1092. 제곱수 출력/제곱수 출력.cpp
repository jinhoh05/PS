#include <iostream>

using namespace std;
using ull = unsigned long long;

ull sum=1,res=1;


ull calc(ull x,ull y){
    if(y == 0) return 1;


    if(y % 2 == 0){
        sum=calc(x,y/2);
        res=sum*sum;
        res=res%20091024;
    }

    else if(y % 2 == 1){
        sum=calc(x,y-1);
        res=sum*x;
        res=res%20091024;

    }

    return res;
}

int main()
{
    ull x,y,cnt=1;

    scanf("%llu %llu",&x, &y);

    calc(x,y);

    printf("%llu",res);


    return 0;
}
//987654321 10248