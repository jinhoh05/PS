#include<bits/stdc++.h>
using namespace std;

int N;
int ar[500500],br[500500],cr[500500];
int m[1000005];
vector<long long> v;
long long ans = 0;

long long BTW(int s1,int e1,int s2,int e2){
    long long ret = 0;
    v.clear();
    for(int i=s1;i<=e1;i++) v.push_back(cr[i]);
    sort(v.begin(),v.end());
    for(int j=s2;j<=e2;j++){
        long long l = lower_bound(v.begin(),v.end(),cr[j]) - v.begin();
        if(cr[j] < v[0]) l = 0;
        ret += (v.size() - l);
    }
    return ret;
}

long long Query(int s,int e){
    if(s==e) return 0;
    if(e==s+1) return cr[e] < cr[s];
    long long ret = BTW(s,(s+e)/2,(s+e)/2+1,e);
    ret += (Query(s,(s+e)/2) + Query((s+e)/2+1,e));
    return ret;
}

int main(){
    ///freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&ar[i]);
        m[ar[i]] = i;
    }
    for(int i=0;i<N;i++) scanf("%d",&br[i]);
    for(int i=0;i<N;i++) cr[i] = m[br[i]];

    ans = Query(0,N-1);

    printf("%lld",ans);
    return 0;
}
