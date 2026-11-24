#include <bits/stdc++.h>

using namespace std;
int p;
int beer[1005],DP[1005][1005];

///DP[i][j]=i번째 사람부터 j번째 사람까지 모두 악수를 할때 같은 브랜드의 맥주를 좋아하는 사람끼리 악수한 수의 최대값

int dynamic(){
    for(int j=2;j<=p;j++){
        for(int i=j-1;i>=1;i--){
            if((j-i) % 2 != 0){
                if(beer[i] == beer[j]) DP[i][j] = DP[i+1][j-1]+1;
                else DP[i][j]=DP[i+1][j-1];

                int b=0;
                for(int k=2;k<=j-i;k+=2){
                    int temp=DP[i+((j-i)+1-k)][j] + DP[i][j-k];
                    if(b < temp) b=temp;
                }
                DP[i][j]=max(DP[i][j],b);
            }
        }
    }

    return DP[1][p];
}

int main()
{
    scanf("%d",&p);
    for(int i=1;i<=p;i++){
        scanf("%d",&beer[i]);
    }

    printf("%d",dynamic());
    return 0;
}