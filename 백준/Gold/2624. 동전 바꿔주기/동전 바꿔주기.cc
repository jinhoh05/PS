#include <bits/stdc++.h>
using namespace std;
 
int t,k;
int dp[105][10005];
 
 
struct S{
 
    int pi,ni;
 
}coin[1005];
 
bool comp(const S& a,const S& b){
 
    return a.pi < b.pi;
 
}
 
int main(){
    scanf("%d %d", &t,&k);
 
    for(int i=1;i<=k;i++){
        scanf("%d %d",&coin[i].pi,&coin[i].ni);
    }
 
    sort(coin+1,coin+k+1,comp);
 
    dp[0][0]=1;
 
    for(int i=1;i<=k;i++){
        for(int j=0;j<=coin[i].ni;j++){
            for(int f=0;f<=t;f++){
                if(f+coin[i].pi*j > t) break;
                dp[i][f+coin[i].pi*j]+=dp[i-1][f];
            }
        }
    }
 
    printf("%d", dp[k][t]);
    return 0;
}