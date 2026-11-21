#include <bits/stdc++.h>

using namespace std;
int ans(int a,int b,int d,int cnt){
    for(int i=0;i<d-2;i++){
        a=b;
        b=cnt;
        cnt=a+b;

    }
    return cnt;
}

int main()
{
    int d,k,a,b;
    scanf("%d %d",&d,&k);
    int cnt=0,sum=0,cmp=0;
    for(int i=1;i<k;i++){
        a=i;
        for(int j=1;j<k;j++){
            b=j;
            cnt=a+b;
            if(ans(a,b,d,cnt) == k){
                printf("%d\n%d",b,b+a);
                return 0;
            }
        }
    }



    return 0;
}