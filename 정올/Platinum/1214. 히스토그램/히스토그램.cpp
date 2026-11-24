#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int n;
long long int h,w[100005],stk[100005];
long long int sum=0,cnt=0,ans,r,l;
 
int main()
{
    scanf("%lld",&n);
 
    for(int i=0;i<n;i++){
        sum=0;
        scanf("%lld",&h);
 
        while(cnt > 0 && stk[cnt-1] >= h){
            sum+=w[cnt-1];
            if(ans < stk[cnt-1] * sum) ans=stk[cnt-1] * sum;
            cnt--;
        }
        stk[cnt]=h;
        w[cnt++]=sum+1;
    }
 
    sum=0;
    while(cnt > 0){
        sum+=w[cnt-1];
        if(ans < stk[cnt-1] * sum) ans=stk[cnt-1] * sum;
        cnt--;
    }
    
    
    printf("%lld",ans);
 
 
    return 0;
}