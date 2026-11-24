#include <bits/stdc++.h>

using namespace std;
int n;

struct Data{

    int lev,st,fin;

}a[505];

bool comp(const Data& a,const Data& b){
    return a.fin < b.fin;
}

int main(){

    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i].lev,&a[i].st,&a[i].fin);
    }

    sort(a+1,a+n+1,comp);
    int cnt=0,sum=1;
    int b[505];

    b[0]=a[1].lev;
    for(int i=2;i<=n;i++){
        if(a[i].st >= a[sum].fin){
            b[++cnt]=a[i].lev;
            sum=i;
        }
    }


    printf("%d\n",cnt+1);
    for(int i=0;i<=cnt;i++){
        printf("%d ",b[i]);
    }


    return 0;
}