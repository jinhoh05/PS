#include <bits/stdc++.h>
 
using namespace std;
int n,m,got[25][305],give[305],DP[25][305],P[25][305];
///DP[i][j]=i번쨰 기업까지 j만원을 투자헀을때 얻을수 있는 최대 수익
 
void path(int idx,int i,int cur){
    if(i <= 0) return;
    path(P[i-1][idx],i-1,cur-(cur-idx));
    printf("%d ",cur-idx);
}
 
void dynamic(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int Max=0;
            for(int k=0;k<=j;k++){
                int temp=DP[i-1][j-k] + got[i][k];
                if(Max < temp){
                    Max=temp;
                    P[i][j]=j-k;
                }
            }
            DP[i][j]=Max;
        }
    }
 
    printf("%d\n",DP[m][n]);
    path(P[m][n],m,n);
}
 
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&give[i]);
        for(int j=1;j<=m;j++){
            scanf("%d",&got[j][i]);
        }
    }
 
    dynamic();
 
    return 0;
}