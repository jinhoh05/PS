#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,m,sum1,sum2,ans,cost[50005],cnt[50005];

struct Data1
{
    ll p,c;
    bool operator<(const Data1 &r)const{
        return c<r.c;
    }
};

struct Data2
{
    ll p,c;
    bool operator<(const Data2 &r)const{
        return p<r.p;
    }
};

struct Data3
{
    ll p,c;
    bool operator<(const Data3 &r)const{
        return p-c>r.p-r.c;
    }
}arr[50005];

priority_queue<Data1>lpq;
priority_queue<Data2>rpq;

void lchk(ll idx)
{
    sum1+=arr[idx].c;
    lpq.push({arr[idx].p,arr[idx].c});
    if (lpq.size()>k){
        auto tmp=lpq.top();
        sum1-=tmp.c;
        lpq.pop();
    }
}

void rchk(ll idx)
{
    sum2+=arr[idx].p;
    rpq.push({arr[idx].p,arr[idx].c});
    while (!rpq.empty() && sum2>cost[idx-1]){
        auto tmp=rpq.top();
        sum2-=tmp.p;
        rpq.pop();
    }
}

int main()
{
    scanf("%lld %lld %lld",&n,&k,&m);
    for (int i=1;i<=n;i++){
        scanf("%lld %lld",&arr[i].p,&arr[i].c);
    }
    sort(arr+1,arr+1+n);
    for (int i=1;i<=n;i++){
        lchk(i);
        cost[i]=m-sum1;
        cnt[i]=lpq.size();
        //printf("%d %d\n",cost[i],cnt[i]);
    }

    while (!lpq.empty() && sum1 > m) {
        sum1 -= lpq.top().c;
        lpq.pop();
    }

    ans = lpq.size();

    for (int i=n-1;i>=0;i--){
        rchk(i+1);
        if (cost[i]<0) continue;
        ans=max(ans,cnt[i]+(ll)rpq.size());
    }
    printf("%lld",ans);
}
