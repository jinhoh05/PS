#include <bits/stdc++.h>

using namespace std;
int n,k,ans=-1e9,l,hap;
int a[100005],b[100005],ans_a,ans_b;

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=k;i++) hap+=a[i];

    b[++l]=hap;
    for(int i=k+1;i<=n;i++){
        hap=hap-a[i-k]+a[i];
        b[++l]=hap;
    }

    for(int i=1;i<=l;i++){
        ans=max(ans,b[i]);
    }

    printf("%d",ans);
    return 0;
}