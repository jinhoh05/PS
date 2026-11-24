#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n,m,k;
int a[505],arr[505];
int sum,cnt;

int check(int mid){
    int hap=0;
    cnt=1;
    for(int i=1;i<=n;i++){
        hap+=a[i];
        if(hap > mid){
            cnt++;
            hap=a[i];
        }
    }

    if(cnt <= m){
        return 1;
    }
    return 0;
}


int add(int lev){
    int ad=lev;

    while(ad < m){
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

int in(int low){
    int hap=0,lev=1,x=0;
    for(int i=n;i>=1;i--){
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

    int low,mid,high;

    scanf("%d",&k);

    for(int j=1;j<=k;j++){
        low=high=0;

        scanf("%d %d",&n,&m);

        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            low=max(a[i],low);
            high+=a[i];
        }

        while(low <= high){
            mid=(low+high)/2;
            if(check(mid)) high=mid-1;
            else low=mid+1;
        }

        int lev=in(low),f=0;

        for(int i=1;i<=n;i++){
            printf("%d ",a[i]);
            f++;
            if(arr[lev] == f && i != n){
                f=0;
                lev--;
                printf("/ ");
            }
        }

        printf("\n");
    }

    return 0;
}