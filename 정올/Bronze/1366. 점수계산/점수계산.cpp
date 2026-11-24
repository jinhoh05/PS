#include <bits/stdc++.h>

using namespace std;
int num[11],number[1000]={0},hap=0,ans,cnt=0,n;

int main()
{
    //freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        if(num[i]){
            cnt++;
            ans+=cnt;
        }
        else cnt=0;
    }

    printf("%d",ans);

    return 0;
}