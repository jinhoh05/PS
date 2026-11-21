#include <bits/stdc++.h>
 
using namespace std;

int n, k, rn;
int id[100005], w[100005];

long long ans;

struct st{
    int id, w, cnum;
    bool operator <(const st&r)const{
        if(w != r.w) return w > r.w;
        return cnum > r.cnum;
    }
}result[100005];
 
priority_queue<st> pq;
 
bool comp(const st& a, const st& b){
    if(a.w != b.w) return a.w < b.w;
    return a.cnum > b.cnum;
}
 
int main()
{
    scanf("%d %d", &n, &k);
   
    int i;
    for(i=1;i<=n;i++){
        scanf("%d %d", &id[i], &w[i]);
    }
 
    for(i=1;i<=k && i <= n;i++){
        pq.push({id[i], w[i], i});
    }
 
    for(;i<=n;i++){
        st t = pq.top();
        pq.pop();
        result[++rn] = t;
        pq.push({id[i], w[i] + t.w, t.cnum});
    }
 
    while(!pq.empty()){
        result[++rn] = pq.top();
        pq.pop();
    }
 
    sort(result + 1,result + rn + 1,comp);
 
    for(i=1;i<=rn;i++){
        ans += (long long)result[i].id * i;
    }
 
    printf("%lld", ans);
 
    return 0;
}