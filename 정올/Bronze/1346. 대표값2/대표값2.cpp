#include <bits/stdc++.h>

using namespace std;
int n,big,bigger,ans=1,num[1005],vt[1005][1005];

int main()
{
    for(int i=1;i<=5;i++){
        scanf("%d",&num[i]);
        big+=num[i];
    }

    sort(num+1,num+5+1);

    printf("%d\n%d",big/5,num[3]);

    return 0;
}