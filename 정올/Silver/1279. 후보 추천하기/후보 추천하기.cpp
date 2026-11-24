#include <bits/stdc++.h>

using namespace std;
int n,k,small=1e9,l,hap,ans,cnt,vt[1005];
struct data{
    int x,y,z;
    bool operator<(const data&t)const{
        if(y==t.y) return z > t.z;
        return y < t.y;
    }

}a[1005];

void change(){
    sort(a+1,a+n+1);
    vt[a[1].x]=0;
    for(int i=1;i<=cnt-1;i++){
        a[i]=a[i+1];
    }
    cnt=n-1;
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&l);
        if(vt[l]==0){
            if(cnt==n) change();
            a[++cnt].x=l;
            a[cnt].y=1;
            a[cnt].z=0;
            vt[l]=1;
        }

        for(int i=1;i<=cnt;i++){
            if(a[i].x==l) a[i].y++;
            a[i].z++;
        }
    }

    for(int i=1;i<=n;i++){
        printf("%d ",a[i].x);
    }

    return 0;
}