#include <bits/stdc++.h>

using namespace std;
int in,out,in_p,big,ans;

int main()
{
    for(int j=1;j<=4;j++){
        scanf("%d %d",&out,&in);
        in_p-=out;
        in_p+=in;
        ans=max(ans,in_p);
    }
    printf("%d",ans);

    return 0;
}