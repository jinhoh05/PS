#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,p,a,b,uD[300010],dD[300010],now,mxans[300010],mnans[300010],tmp,ans1,ans2,t=1;

vector<ll>vec[300010], vec2[300010];
priority_queue<ll,vector<ll>,greater<ll>>dpq;
priority_queue<ll,vector<ll>,greater<ll>>upq;

void bfs()
{
    tmp=n-k;
    while (!upq.empty()){
        now=upq.top();
        upq.pop();
        mxans[now]=tmp++;
        for (int i=0;i<vec2[now].size();i++){
            uD[vec2[now][i]]--;
            if (uD[vec2[now][i]]==0) upq.push(vec2[now][i]);
        }
    }
    tmp=k-1;
    while (!dpq.empty()){
        now=dpq.top();
        dpq.pop();
        mnans[now]=tmp--;
        for (int i=0;i<vec[now].size();i++){
            dD[vec[now][i]]--;
            if (dD[vec[now][i]]==0) dpq.push(vec[now][i]);
        }
    }
}

int main()
{
    scanf("%lld %lld %lld",&n,&k,&p);
    for (int i=1;i<=p;i++){
        scanf("%lld %lld",&a,&b);
        vec[a].push_back(b);
        vec2[b].push_back(a);
        dD[b]++;
        uD[a]++;
    }
    for (int i=0;i<k;i++){
        if (uD[i]==0){
            upq.push(i);
        }
        
        if (dD[i] == 0){
            dpq.push(i);
        }
    }
    bfs();
    for (int i=0;i<k;i++){
        ans1=(ans1 + mxans[i]*t)%1000000007;
        ans2=(ans2 + mnans[i]*t)%1000000007;
        t=(t*n)%1000000007;
    }
    printf("%lld",((ans1+1000000007)-ans2)%1000000007);
}
