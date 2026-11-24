#include <bits/stdc++.h>
 
using namespace std;
int n,m,DP[1005][1005],Map[1005][1005],hap[1005][1005],hap_r[1005][1005],hap_l[1005][1005];
int dx[3]={0,1,0};
int dy[3]={-1,0,1};
int cnt,ans;

void dynamic(int k){
    if(k > n) return;
        
    for(int i=1;i<=n;i++){
        hap[k][i]=DP[k-1][i]+Map[k][i];
    }
    
    hap_r[k][1]=hap[k][1];
    hap_l[k][n]=hap[k][n];
    
    for(int i=2;i<=n;i++){
        hap_r[k][i]=max(hap_r[k][i-1]+Map[k][i],hap[k][i]);
    }
    
    for(int i=n-1;i>=1;i--){
        hap_l[k][i]=max(hap_l[k][i+1]+Map[k][i],hap[k][i]);
    }
    
    for(int i=1;i<=n;i++){
        DP[k][i]=max(hap_r[k][i],hap_l[k][i]);
    }
    
    dynamic(k+1);
}
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&Map[i][j]);
        }
    }
    
    for(int i=1;i<=n;i++){
        DP[1][i]=DP[1][i-1]+Map[1][i];
    }
        
    dynamic(2);
    
    printf("%d",DP[n][n]);
 
    return 0;
}