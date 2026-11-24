#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
    scanf("%d",&n);

    int sum=1,ch=1;

    for (int i=1;i<n;i++){
        if (ch == 1){
            sum = sum * 2 + 1;
            sum %= 20100529;
            ch = -1;
        }
        else if (ch == -1){
            sum = sum * 2 - 1;
            sum %= 20100529;
            ch= 1;
        }
    }

    printf("%d", sum);

    return 0;
}