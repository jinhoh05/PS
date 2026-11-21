#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
int n,a[85],b[85],f=0;
 
void output(){
 
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
}
 
void check(int x){
    int cnt=0;
    int mid=x/2;
    int sum=0;
    int ans=0;
 
    if(x > n){
        output();
        f=1;
        return;
    }
 
    for(int j=1;j<=3;j++){
        cnt=0;
        ans=0;
        a[x]=j;
        for(int i=1;i<=mid;i++){
            cnt++;
            sum=0;
            for(int k=x;k>x-cnt;k--){
                if(a[k] == a[k-cnt]){
                    sum++;
                }
            }
 
            if(sum == i){
                ans=1;
                break;
            }
        }
        if(ans == 0){
            check(x+1);
            if(f==1) return;
        }
    }
}
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    scanf("%d",&n);
 
    a[1]=1;
 
    check(2);
 
    return 0;
}