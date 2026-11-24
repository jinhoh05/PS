#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sum=0;
int k;
int a[15];
int b[15];
void change(int cnt,int n){
    if(cnt == 0){
        printf("NONE");
        return;
    }
    if(a[cnt] < n){
        if(cnt != k){
            for(int i=1;i<cnt;i++){
                printf("%d ",a[i]);
            }
            printf("%d ",a[cnt]+1);
            sum=a[cnt]+2;
            for(int i=cnt;i<k;i++){
                printf("%d ",sum);
                sum++;
            }
        }
        else{
            for(int i=1;i<cnt;i++){
                printf("%d ",a[i]);
            }
            printf("%d",a[cnt]+1);
        }
    }

    else{
        change(cnt-1,n-1);
    }
}

int main(){
    int n;
    scanf("%d %d",&n,&k);

    for(int i=1;i<=k;i++){
        scanf("%d",&a[i]);

    }

    change(k,n);
    return 0;
}