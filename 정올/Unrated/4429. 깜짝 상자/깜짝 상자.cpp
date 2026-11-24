#include <bits/stdc++.h>

using namespace std;
int n,box[100005],cnt;
int hap=1;

bool comp(int a,int b){
     return a > b;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&box[i]);
        if(box[i]>=1) cnt++;
    }
    if(cnt==n){
        printf("%d\n%d",n,n);
        return 0;
    }
    sort(box+1,box+n+1);

    for(int i=1;i<=n;i++){
        hap+=(box[i]-1);
        if(hap==0){
            printf("%d\n",i);
            break;
        }
    }

    hap=1;
    sort(box+1,box+n+1,comp);
    for(int i=1;i<=n;i++){
        hap+=(box[i]-1);
        
        if(hap==0){
            printf("%d",i);
            return 0;
        }
    }

    return 0;
}