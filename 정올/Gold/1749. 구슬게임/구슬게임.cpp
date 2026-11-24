#include <bits/stdc++.h>

using namespace std;
int b[5],DP[505][505];

void dynamic(){
    for(int i=0;i<=500;i++){
        for(int j=0;j<=500;j++){
            for(int k=1;k<=3;k++){
                if(i >= b[k] && DP[i-b[k]][j]==0) DP[i][j]=1;
                else if(j >= b[k] && DP[i][j-b[k]]==0) DP[i][j]=1;
            }
        }
    }

}

int main()
{
    for(int i=1;i<=3;i++) scanf("%d",&b[i]);

    dynamic();

    for(int i=1;i<=5;i++){
        int k1,k2;
        scanf("%d %d",&k1,&k2);
        if(DP[k1][k2]) printf("A\n");
        else printf("B\n");
    }

    return 0;
}