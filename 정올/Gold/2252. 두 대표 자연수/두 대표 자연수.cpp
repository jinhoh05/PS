#include <bits/stdc++.h>

using namespace std;
long long int sub[5000002],multi[5000002],arr[5000002],vt[5000002];
long long int ans=1234567678914,sum,all_hap,ms,mul,a,f_hap,hap,hap_,k,n,st,fin,answer,cnt;

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        all_hap+=a;
        vt[a]++;
    }

    for(int i=1;i<=10000;i++){
        while(vt[i]>0){
            arr[++cnt]=i;
            vt[i]--;
        }
    }

    if(n%2!=0) printf("%d ",arr[n/2+1]);
    else{
        int num=arr[n/2];
        for(int i=1;i<=n;i++){
            hap+=arr[i]-num;
        }
        int num_=arr[n/2+1];
        for(int i=1;i<=n;i++){
            hap_+=arr[i]-num;
        }
        if(hap>hap_) printf("%d ",num_);
        else printf("%d ",num);
    }

    hap=0;
    if(all_hap%n>0){
        k=all_hap/n+1;
        for(int i=1;i<=n;i++){
            hap+=(arr[i]-k)*(arr[i]-k);
        }
    }
    k=all_hap/n;
    for(int i=1;i<=n;i++){
        f_hap+=(arr[i]-k)*(arr[i]-k);
    }

    if(hap < f_hap && hap != 0) printf("%lld",k+1);
    else printf("%lld",k);

    return 0;
}