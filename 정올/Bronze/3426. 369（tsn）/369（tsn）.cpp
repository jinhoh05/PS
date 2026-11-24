#include <bits/stdc++.h>

using namespace std;
int n,square[100005],ans,big,num;
int vt[26][26];

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        big=i;
        while(big>0){
            num=big%10;
            if(num!=0){
                if(num%3==0 || num%6==0 || num%9==0) ans++;
            }
            big/=10;
        }
    }


    printf("%d",ans);

    return 0;
}