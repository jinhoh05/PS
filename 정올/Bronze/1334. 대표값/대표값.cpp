#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);

    int num[11],number[1000]={0},hap=0,ans,cnt=0;
    for(int i=1;i<=10;i++){
        scanf("%d",&num[i]);
        hap+=num[i];
    }

    for(int i=1;i<=10;i++){
        if(cnt < number[num[i]]++){
            ans=num[i];
            cnt=number[num[i]];
        }
    }

    printf("%d\n%d",hap/10,ans);

    return 0;
}