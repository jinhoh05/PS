#include <bits/stdc++.h>

using namespace std;
int hap,temp,dis,n,cnt,DP[105],P[105];
struct data{
    int p,t;
}jungbi[105];

void path(int idx){
    if(idx <= 0){
        printf("%d\n",cnt);
        return;
    }
    cnt++;
    path(P[idx]);
    printf("%d ",idx);
}

void dynamic(){
    for(int i=1;i<=n+1;i++){
        int small=1e9,pre;
        for(int j=i-1;j>=0;j--){
            if(jungbi[i].p - jungbi[j].p <= dis){
                if(small > DP[j]){
                    small=DP[j];
                    pre=j;
                }
            }
            else break;
        }
        DP[i]=small+jungbi[i].t;
        P[i]=pre;
    }

    printf("%d\n",DP[n+1]);
    if(DP[n+1] != 0) path(P[n+1]);
}

int main()
{
    scanf("%d %d",&dis,&n);
    for(int i=1;i<=n+1;i++){
        scanf("%d",&temp);
        hap+=temp;
        jungbi[i].p=hap;
    }
    for(int i=1;i<=n;i++) scanf("%d",&jungbi[i].t);

    if(hap<=dis){
        printf("0");
        return 0;
    }

    dynamic();

    return 0;
}