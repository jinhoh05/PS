#include <bits/stdc++.h>

using namespace std;
int n;
int dp[105];
int path[105];
int b[105];
struct Data{
    int area,h,w,lev;
}brick[105];

bool comp(const Data& a,const Data& b){
    return a.area < b.area;
}

void trace(int k,int cnt){
    if(k == 0){
        printf("%d\n",cnt);
        return ;
    }
    trace(path[k],cnt+1);
    printf("%d\n",brick[k].lev);
}

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&brick[i].area,&brick[i].h,&brick[i].w);
        brick[i].lev=i;
    }

    sort(brick+1,brick+n+1,comp);

    int br=1;
    for(int i=1;i<=n;i++){
        dp[i]=brick[i].h;
        for(int j=1;j<i;j++){
            if(brick[i].w > brick[j].w){
                if(dp[i] < dp[j]+brick[i].h){
                    dp[i]=dp[j]+brick[i].h;
                    path[i]=j;
                }
            }
        }
        if(dp[br] < dp[i]) br=i;
    }

    trace(br, 0);

    return 0;
}