#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n;
int a[500005];
int hil[500005];
int mmr[500005];
int cnt=0,sum=1;
  
int main()
{
  
    scanf("%d",&n);
  
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  
  
    for(int i=n;i>0;i--){
        if(n==1) break;
        sum=1;
        while(i < n && mmr[cnt-1] < a[i]){
            if(hil[i+sum] != 0){
                while(hil[i+sum] != 0) sum++;
            }
            hil[i+sum]=i;
            mmr[--cnt]=0;
            sum++;
            if(cnt == 0) break;
        }
        mmr[cnt++]=a[i];
    }
  
    for(int i=1;i<=n;i++){
        printf("%d ",hil[i]);
    }
  
    return 0;
}