#include <bits/stdc++.h>

using namespace std;
int n,k,small=1e9,l,hap;
double a[100005],ans;

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
    }
    sort(a+1,a+n+1);

    for(int i=k+1;i<=n-k;i++){
        ans+=a[i];
    }
    printf("%0.2f\n",ans/(n-(k*2)));
    ans=0;


    for(int i=1;i<=n;i++){
        if(i<=k) ans+=a[k+1];
        else if(i >n-k) ans+=a[n-k];
        else ans+=a[i];
    }
    printf("%0.2f",ans/n);

    return 0;
}