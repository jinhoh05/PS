#include <bits/stdc++.h>

using namespace std;
int n,big;
int main()
{
    for(int i=1;i<=5;i++){
        scanf("%d",&n);
        big+=n*n;
    }

    printf("%d",big%10);

    return 0;
}