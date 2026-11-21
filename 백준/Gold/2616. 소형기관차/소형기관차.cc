#include <bits/stdc++.h>
 
using namespace std;
int n,m,train[50005],c[50005],DP[5][50005],ans;
 
int dynamic(){
    for(int i=1;i<=3;i++){
        for(int j=m*i;j<=n;j++){
            DP[i][j]=max(DP[i-1][j-m]+train[j],DP[i][j-1]);
        }
    }
 
    return DP[3][n];
}
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&train[i]);
    }
    scanf("%d",&m);
 
    int temp1=0,temp2=0;
    for(int i=n;n-i<m;i--){
        temp2+=train[i];
    }
 
    for(int i=n;i>=m;i--){
        temp1=train[i];
        train[i]=temp2;
        temp2-=temp1;
        temp2+=train[i-m];
    }
 
    //for(int i=1;i<=n;i++) printf("%d ",train[i]);
 
    printf("%d",dynamic());
 
    return 0;
}