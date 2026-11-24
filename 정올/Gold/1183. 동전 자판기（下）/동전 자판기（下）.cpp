#include <bits/stdc++.h>

using namespace std;
int n,w,coin[6];
int won[6]={500,100,50,10,5,1};
int ans[6];
int cnt;

void price(){

    for(int i=0;i<6;i++){
        if(coin[i] >= n / won[i]){
            ans[i]=coin[i] - n/won[i];
            n=n%won[i];
        }
        else{
            ans[i]=0;
            n=n-(coin[i]*won[i]);
        }
        cnt+=ans[i];
        //printf("%d ",n);
    }

}

int main()
{
    scanf("%d",&w);

    for(int i=0;i<6;i++){
        scanf("%d",&coin[i]);
    }

    n=(coin[0] * 500) + (coin[1] * 100) + (coin[2] * 50) + (coin[3] * 10) + (coin[4] * 5) + (coin[5] * 1) - w;

    price();

    printf("%d\n",cnt);

    for(int i=0;i<6;i++){
        printf("%d ",ans[i]);
    }

    return 0;
}