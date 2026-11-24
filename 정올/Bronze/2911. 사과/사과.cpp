#include <bits/stdc++.h>

using namespace std;
int n,k,a,b,ans;
int boy[7],girl[7];


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        ans+=b%a;
    }

    printf("%d",ans);
    return 0;
}