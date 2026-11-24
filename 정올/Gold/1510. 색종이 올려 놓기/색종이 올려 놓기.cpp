#include <bits/stdc++.h>

using namespace std;
int n;
int dp[105];
struct data{

    int x,y;

}paper[105];


bool comp(const data& a,const data& b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d %d",&paper[i].x,&paper[i].y);
        dp[i]=1;
        if(paper[i].x > paper[i].y){
            swap(paper[i].x,paper[i].y);
        }
    }

    sort(paper+1,paper+n+1,comp);

    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            if(paper[i].x <= paper[j].x && paper[i].y <= paper[j].y){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }

    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,dp[i]);
    }

    printf("%d",mx);

    return 0;
}