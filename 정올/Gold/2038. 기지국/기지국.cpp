#include <bits/stdc++.h>

using namespace std;
int n,DP[10005];
struct data{
    int x,y;
    bool operator<(const data&t)const{
        return x<t.x;
    }

}build[10005];

int solve(int k){
    if(DP[k]) return DP[k];
    if(k<=1) return DP[k]=abs(2*build[k].y);

    int ans=1e9,Max=0;
    for(int i=k-1;i>=0;i--){
        Max=max(Max,abs(build[i+1].y));
        ans=min(ans,solve(i)+max(2*Max,build[k].x-build[i+1].x));
    }

    return DP[k]=ans;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&build[i].x,&build[i].y);
    }
    sort(build+1,build+n+1);

    printf("%d",solve(n));

    return 0;
}