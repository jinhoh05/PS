#include <bits/stdc++.h>

using namespace std;
int n,m,cnt,hap;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        hap=0;
        m=i;
        while(m>0){
            hap+=m%10;
            m/=10;
        }
        if(i%hap==0) cnt++;
    }
    printf("%d",cnt);

    return 0;
}