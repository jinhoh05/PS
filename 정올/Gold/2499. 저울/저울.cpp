#include <bits/stdc++.h>

using namespace std;
int n,a[1005],sum,vt[100005];

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){
        if(sum + 1 >= a[i]){
            sum+=a[i];
        }
        else break;
    }

    printf("%d",sum+1);


    return 0;
}