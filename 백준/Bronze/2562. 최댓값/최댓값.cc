#include <bits/stdc++.h>

using namespace std;
int n,big,ans;
int main()
{
    for(int i=1;i<=9;i++){
        scanf("%d",&n);
        if(big < n){
            big=n;
            ans=i;
        }
    }

    printf("%d\n%d",big,ans);

    return 0;
}