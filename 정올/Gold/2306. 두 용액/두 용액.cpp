#include <bits/stdc++.h>

using namespace std;
long long int n,m,k,c,ans=987987654321,p,sol[100005],l=1,r,a,b,hap,val;

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&sol[i]);
    }
    r=n;
    sort(sol+1,sol+n+1);

    while(l<r){
        hap=sol[l]+sol[r];
        val=hap;
        if(val<0) val*=-1;
        if(ans > val){
            ans=val;
            a=sol[l];
            b=sol[r];
        }
        if(hap<0) l++;
        else r--;
    }

    printf("%lld %lld",a,b);

    return 0;
}