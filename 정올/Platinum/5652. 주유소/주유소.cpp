#include <bits/stdc++.h>
using namespace std;
int n,k,a,b,ans,chk[200010];

vector<int>vec[200010];

int dfs(int idx)
{
    chk[idx]=1;
    int ma1=0,ma2=0,tmp,fl=0;
    for (int i=0;i<vec[idx].size();i++){
        if (chk[vec[idx][i]]) continue;
        fl=1;
        tmp=dfs(vec[idx][i]);
        if (ma1<tmp){
            ma2=ma1;
            ma1=tmp;
        }
        else if (ma2<tmp) ma2=tmp;
    }
    if (k<ma1+ma2+1){
        ans++;
        return 0;
    }
    return ma1+1;
}

int main()
{
    scanf("%d %d",&n,&k);
    for (int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int tt=dfs(1);
    printf("%d",ans);
}
