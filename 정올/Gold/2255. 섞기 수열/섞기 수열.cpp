#include <bits/stdc++.h>

using namespace std;
int n;
int a[20005];
int vt[20005];
int q[20005];

int gcd(int x,int y){
    if(y == 0){
        return x;
    }
    else{
        return gcd(y,x%y);
    }
}

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    int now,cnt,sum;

    for(int i=1;i<=n;i++){
        sum=1;
        now=cnt=a[i];
        if(vt[i] == 0){
            while(1){
                vt[now]=1;
                now=a[now];
                if(now == cnt){
                    q[i]=sum;
                    break;
                }
                sum++;
            }
        }
    }

    int mx=q[1];
    for(int i=1;i<=n;i++){
        if(q[i] != 0){
            mx= mx / gcd(q[i],mx) * q[i];
        }
    }

    printf("%d",mx);

    return 0;
}