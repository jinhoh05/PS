#include <bits/stdc++.h>

using namespace std;
int n,ans;
int dp[10005];
int path[10005];
int renum[10005], a[10005], b[10005];
vector <int> result;

void trace(int k){
    if(k == 0){
        return;
    }
    trace(path[k]);
    result.push_back(a[b[k]]);
}

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        renum[a[i]]=i;
    }

    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        b[i]=renum[b[i]];

    }

    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(b[j] < b[i]){
                if(dp[i] < dp[j]+1){
                    dp[i]=dp[j]+1;
                    path[i]=j;
                }
            }
        }
        if(dp[ans] < dp[i]) ans=i;
    }

    trace(ans);

    sort(result.begin(),result.end());
    printf("%d\n",result.size());
    for(int i:result){
        printf("%d ",i);
    }
    return 0;
}