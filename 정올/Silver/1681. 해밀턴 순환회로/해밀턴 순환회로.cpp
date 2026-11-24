#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,sum=1000000;
int square[15][15],l[30],r[30],chk[30];
int A[15],used[15];

void permut(int lev,int as,int cost){
    if(cost >= sum) return;
    if(as >= n){
        //output();
        if(square[lev][1] && sum > cost+square[lev][1]){
            sum=cost+square[lev][1];
        }
        return;
    }

    for(int i=2;i<=n;i++){
         if(used[i] == 0 && square[lev][i] != 0){
            used[i]=1;
            permut(i,as+1,cost+square[lev][i]);
            used[i]=0;
         }
    }

}

int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);

    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&square[i][j]);
        }
    }



    permut(1,1,0);


    printf("%d",sum);
    return 0;
}