#include <bits/stdc++.h>

using namespace std;
int n;
int koi[100005];
int a,b,mini,sum;
int l=1,r;

int main()
{
    scanf("%d",&n);
    r=n;

    for(int i=1;i<=n;i++){
        scanf("%d",&koi[i]);
    }

    mini=abs(koi[l] + koi[r])+1;

    while(l < r){
        sum=koi[l] + koi[r];
        if(abs(sum) < mini){
            mini=abs(sum);
            a=koi[l];
            b=koi[r];
        }
        if(sum < 0) l++;
        else r--;
    }

    printf("%d %d",a,b);
    return 0;
}