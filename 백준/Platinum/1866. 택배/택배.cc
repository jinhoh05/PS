#include <bits/stdc++.h>
 
using namespace std;
 
///DP[i] :  1번째부터 i번째까지 택배를 배달했을 때 최솟값
///i번쨰 택배 트럭으로 운송 : DP[i] = DP[i-1] + del[i] * t
///i 이하의 j를 잡아 j부터 i까지 헬리콥터로 운송(mid를 기준으로 반으로 나눔)
///왼쪽 : {del[mid] * (mid-j+1) - (j부터 mid까지 좌표의 합)} * t
///오른쪽 : {(mid부터 j까지 좌표의 합) - arr[mid] * (i-mid+1)} * t
///DP[i] = min(DP[i], DP[j-1] + 왼쪽 + 오른쪽)
 
int n,DP[3005],del[3005],t,h,sum[3005];
 
int solve(){
    for(int i=1;i<=n;i++) sum[i]=sum[i-1] + del[i];
 
    for(int i=1;i<=n;i++){
        DP[i]=DP[i-1] + del[i] * t;
     
        for(int j=i;j>=1;j--){
            int mid=(i+j) / 2;
            int left=(del[mid] * (mid - j + 1) - (sum[mid] - sum[j-1])) * t;
            int right=((sum[i] - sum[mid - 1]) - (del[mid] * (i - mid + 1))) * t;
 
            int cost=left + right + h;
            DP[i]=min(DP[i],DP[j-1] + cost);
        }
    }
 
    return DP[n];
}
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&del[i]);
    }
    scanf("%d %d",&t,&h);
 
    sort(del+1,del+n+1);
 
    printf("%d",solve());
 
    return 0;
}