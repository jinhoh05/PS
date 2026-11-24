#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int a[10000]={0};
int m;
int recycle(int cnt){

    for(int i=1;i<=cnt;i++){
        for(int j=i;j<=cnt;j++){
            if(a[i] == a[j] && i != j){
                printf("%d",j-i);
                return 1;
            }
        }
    }

    return 0;
}

void cycle(int n,int p,int cnt){
    n=n*m%p;
    a[cnt]=n;
    cnt++;
    if(recycle(cnt-1)){
        return;
    }
    cycle(n,p,cnt);

}

int main()
{
    int n,p;

    scanf("%d %d",&n,&p);
    m=n;
    cycle(n,p,1);

    return 0;
}