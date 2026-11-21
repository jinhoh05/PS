#include <bits/stdc++.h>

using namespace std;
int n, a, b, c, cnt;

int hansoo(){
    if(n < 100) return n;
    else{
        for(int i=100;i<=n;i++){
            a = i / 100;
            b = (i % 100) / 10;
            c = (i % 100) % 10;
            if(a - b == b - c) cnt++;
        }
        return (99 + cnt);
    }

    return 0;
}

int main()
{
    scanf("%d",&n);

    printf("%d", hansoo());

    return 0;
}
