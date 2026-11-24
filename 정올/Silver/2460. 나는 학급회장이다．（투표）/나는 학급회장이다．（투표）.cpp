#include <bits/stdc++.h>

using namespace std;
int n,a[4],ans=1;

int main()
{
    scanf("%d",&n);
    int i,j,k;

    for(i=1;i<=n;i++){
        for(j=1;j<4;j++){
            scanf("%d",&k);
            a[j] += k << 10;
            if(k == 3) a[j]++;
        }
    }
    for(i=2;i<4;i++){
        if(a[ans] < a[i]) ans=i;
        else if(a[ans] == a[i]) a[(ans=0)] = a[i];
    }
    printf("%d %d",ans,a[ans]>>10);

    return 0;
}