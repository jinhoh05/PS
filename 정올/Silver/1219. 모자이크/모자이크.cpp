#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int b[1000001];
int sum=0;
int n,m;
int p,q;
int cnt=0;

int fcheck(){
    int w=0;
    for(int k=sum;k<=n;k++){
        for(int i=1;i<=q;i++){
            if(w >= b[i]) continue;
            w=b[i]+k-1;
            cnt++;
        }
    if(cnt <= p){
        printf("%d",k);
        return 0;
    }
    w=0;
    cnt=0;
    }
}

int main()
{

    scanf("%d %d %d %d",&n,&m,&p,&q);

    for(int i=1;i<=q;i++){
        scanf("%d %d",&a[i],&b[i]);
        if(a[i] > sum) sum=a[i];
    }

    sort(b+1,b+q+1);

    fcheck();

    return 0;
}