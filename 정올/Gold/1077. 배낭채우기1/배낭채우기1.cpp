#include <bits/stdc++.h>
 
using namespace std;
int n,w;
int dp[10005];
 
struct data{
 
    int wi,pi;
 
}dia[1005];
 
bool comp(const data&a,const data&b){
 
    return a.wi < b.wi;
}
 
int main()
{
    scanf("%d %d",&n,&w);
 
    for(int i=1;i<=n;i++){
        scanf("%d %d",&dia[i].wi,&dia[i].pi);
    }
 
    sort(dia+1,dia+n+1,comp);
 
    for(int i=1;i<=w;i++){
        for(int j=1;j<=n;j++){
            if(dia[j].wi <= i){
                if(dp[i-dia[j].wi]+dia[j].pi > dp[i]){
                    dp[i]=dp[i-dia[j].wi]+dia[j].pi;
                }
            }
            else break;
        }
    }
 
    printf("%d",dp[w]);
 
    return 0;
}