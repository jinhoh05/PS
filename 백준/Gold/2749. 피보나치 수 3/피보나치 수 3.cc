#include <bits/stdc++.h>

using ull = unsigned long long;
using namespace std;

const ull INF = 1000000;

ull n;
ull fibo[1500005];

void fibonacci(){
    fibo[1] = 1;

    for(int i=0;i<=1500000;i++) {
        fibo[i + 2] = (fibo[i + 1] + fibo[i]) % INF;
    }
}

int main(){

    scanf("%llu", &n);

    fibonacci();

    printf("%d", fibo[n % 1500000]);

    return 0;
}
