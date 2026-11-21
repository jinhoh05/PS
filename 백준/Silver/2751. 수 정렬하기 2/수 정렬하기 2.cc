#include <bits/stdc++.h>

using namespace std;
int n;
int a[1000005], arr[2000005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);

    for(int i=1;i<=n;i++) arr[1000000 + a[i]] = 1;

    for(int i=0;i<=2000000;i++){
        if(arr[i]) printf("%d\n", i - 1000000);
    }

    return 0;
}
