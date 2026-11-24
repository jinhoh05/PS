#include <bits/stdc++.h>

using namespace std;
int room[4],p,vt[55];

int dfs(int per){
    if(per==0) return 1;
    for(int i=1;i<=3;i++){
        if(vt[i]==0){
            vt[i]=1;
            for(int j=1;j<=per/room[i];j++){
                if(per-room[i]*j<0) break;
                if(dfs(per-room[i]*j)) return 1;
            }
            vt[i]=0;
        }
    }
    return 0;
}

int main()
{
    for(int i=1;i<=3;i++){
        scanf("%d",&room[i]);
    }
    scanf("%d",&p);

    if(dfs(p)) printf("1");
    else printf("0");

    return 0;
}