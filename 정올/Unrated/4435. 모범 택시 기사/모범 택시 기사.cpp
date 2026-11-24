#include <bits/stdc++.h>

using namespace std;
int n,m,cnt,k,en;
int hap=1;
int vt[50005],ans[50005];

int get_p(int x){
    if(vt[x] == x) return x;
    return vt[x]=get_p(vt[x]);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) vt[i]=i;

    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);

        a = get_p(a);
        b = get_p(b);
        if(a < b) vt[a]=b;
        else vt[b]=a;

        if(a!=b) ans[++k]=i;
    }

    printf("%d\n",k);
    for(int i=1;i<=k;i++){
        printf("%d ",ans[i]);
    }

    return 0;
}