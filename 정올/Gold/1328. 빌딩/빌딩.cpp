#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n;
int a[100005];
int hil[100005];
int arr[100005];
int mmr[100005];
int cnt=0,sum=1;

int main()
{

    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&a[i]);


    for(int i=0;i<n;i++){
        sum=1;
        while(i > 0 && mmr[cnt-1] < a[i]){
            if(hil[i-sum] != 0){
                while(hil[i-sum] != 0){
                    sum++;
                }
            }
            hil[i-sum]=i+1;
            mmr[--cnt]=0;
            sum++;

            if(cnt == 0) break;
        }

        mmr[cnt++]=a[i];
    }

    for(int i=0;i<n;i++){
        printf("%d\n",hil[i]);
    }

    return 0;
}