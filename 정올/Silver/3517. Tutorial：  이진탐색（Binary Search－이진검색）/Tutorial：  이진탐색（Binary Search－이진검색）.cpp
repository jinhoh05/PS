#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,q,h;
int sum=0;
int suml;
int ai[1000005];
int bi[1000005];

int loop(int cnt){
    int st=0;
    int ed=n-1;
    int mid;

    while(st <= ed){
        mid=(ed+st)/2;
        if(ai[mid] == bi[cnt]){
            return mid;
        }

        else if(ai[mid] > bi[cnt]){
            ed=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return -1;
}

int main()
{
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&ai[i]);
    }

    scanf("%d",&q);

    for(int i=0;i<q;i++){
        scanf("%d",&bi[i]);
    }

    for(int i=0;i<q;i++){
        printf("%d ",loop(i));
    }
    return 0;
}