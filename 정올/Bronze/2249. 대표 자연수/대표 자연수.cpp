#include <bits/stdc++.h>

using namespace std;
int n,k,ans,small=1e9,l,hap;
int a[20005],b[100005],ans_a,ans_b;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);

    for(int i=1;i<=a[n];i++){
        hap=0;
        for(int j=1;j<=n;j++){
            hap+=abs(i-a[j]);
        }
        if(hap < small){
            small=hap;
            ans=i;
        }
    }

    printf("%d",ans);
    return 0;
}