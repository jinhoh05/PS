#include <bits/stdc++.h>

using namespace std;
int n,big,bigger,ans,num[6];

int check(){
    int hap=0;
    for(int i=1;i<=3;i++){
        for(int j=i+1;j<=4;j++){
            for(int k=j+1;k<=5;k++){
                hap=max(hap,(num[i]+num[j]+num[k])%10);
            }
        }
    }
    return hap;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&num[j]);
            big=check();
        }
        if(big >= bigger){
            bigger=big;
            ans=i;
        }
    }

    printf("%d",ans);

    return 0;
}