#include <bits/stdc++.h>

using namespace std;
int n,m,l,k,c,hap,ans,p,money[10005],val;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&money[i]);
    }
    scanf("%d",&m);

    sort(money+1,money+n+1);
    val=m/n;

    for(int i=1;i<=n;i++){
        if(val<money[i]) break;
        if(i==n){
            val=money[i];
            break;
        }
        m-=money[i];
        val=m/(n-i);
    }

    printf("%d",val);

    return 0;
}