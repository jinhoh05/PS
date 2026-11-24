#include <bits/stdc++.h>

using namespace std;
int n,a[2005],b[2005],DP[2005][2005];

///DP[i][j] : a카드더미의 i번째 카드와 b카드더미의 j번째 카드까지 사용했을때 얻을 수 있는 최고 점수

int dynamic(){
    for(int i=1;i<=n+1;i++) DP[0][i]=-1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            DP[i][j] = max(DP[i-1][j-1], DP[i-1][j]);
            if(DP[i][j-1] != -1 && a[i] > b[j-1]){
                DP[i][j]=max(DP[i][j], DP[i][j-1] + b[j-1]);
            }
        }
    }

    int temp=0;
    for(int i=1;i<=n+1;i++){
        if(temp < DP[n][i]) temp=DP[n][i];
    }

    return temp;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);

    printf("%d",dynamic());

    return 0;
}