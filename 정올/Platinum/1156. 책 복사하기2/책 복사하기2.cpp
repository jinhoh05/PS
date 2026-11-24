#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int m,k;
long long int a[100005],arr[100005];
int cnt;

int check(long long int mid){
    long long int hap=0;
    cnt=1;
    for(int i=1;i<=m;i++){
        hap+=a[i];
        if(hap > mid){
            cnt++;
            hap=a[i];
        }
    }

    if(cnt <= k){
        return 1;
    }
    return 0;
}


int add(int lev){
    int ad=lev;

    while(ad < k){
        arr[++ad]=1;
        if(arr[lev] > 1){
            arr[lev]--;
        }
        else{
            while(arr[lev] == 1) lev--;
            arr[lev]--;
        }
    }
    return ad;
}

int in(long long int low){
    long long int hap=0,lev=1,x=0;
    for(int i=m;i>=1;i--){
        hap+=a[i];
        x++;
        if(hap + a[i-1] > low){
            arr[lev]=x;
            hap=0;
            lev++;
            x=0;
        }
    }
    arr[lev]=x;

    if(lev < m) lev=add(lev);

    return lev;
}

int main()
{

    long long int low=0,mid,high=0;

    scanf("%d %d",&m,&k);

    for(int i=1;i<=m;i++){
        scanf("%lld",&a[i]);
        low=max(a[i],low);
        high+=a[i];
    }

    while(low <= high){
        mid=(low+high)/2;
        if(check(mid)) high=mid-1;
        else low=mid+1;
    }

    int lev=in(low),f=0;

    for(int i=1;i<=m;i++){
        printf("%lld ",a[i]);
        f++;
        if(arr[lev] == f && i != m){
            f=0;
            lev--;
            printf("/ ");
        }
    }

    return 0;
}