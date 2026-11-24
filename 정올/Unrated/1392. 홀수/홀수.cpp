#include <bits/stdc++.h>

using namespace std;
int n,big,bigger,ans=10000,num[1005],vt[1005][1005];
int prime[105];

int main()
{

    for(int i=1;i<=7;i++){
        scanf("%d",&num[i]);
        if(num[i]%2==1){
            big+=num[i];
            ans=min(ans,num[i]);
        }
    }

    if(big==0) printf("-1");
    else printf("%d\n%d",big,ans);

    return 0;
}