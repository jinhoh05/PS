#include<bits/stdc++.h>
using namespace std;
const int LM = 55;
int A[LM], group[LM];
int n;
int sum=0,mx=-1;
bool used[LM];
vector<int>ret[LM];
//int rets[LM][LM];
bool tour(int tar,int idx,int cur,int c,int st){
    if (c == sum / tar - 1 && cur == 0) {
        for (int i = 1; i <= n; i++) {
            if (!used[i]) group[i] = c;
        }
        return true;
    }

    if(idx > n)return cur==0;

    if(cur == 0)
    {
        int i=1;
        while(i<=n && used[i]) i++;

        used[i]=true;
        group[i]=c;

        int nxt=A[i], nc=c, nst=i+1;

        if(nxt==tar){
            nxt=0;
            nc++;
            nst=1;
        }

        if(tour(tar,idx+1,nxt,nc,nst)) return true;

        used[i]=false;
        return false;
    }

    int L=-1;
    for(int i =st; i<= n; i++){
        if(used[i])continue;
        if(A[i]==L)continue;
        if(cur+A[i]>tar)continue;

        used[i]=true;
        group[i] = c;

        int nxt = cur + A[i], nc = c, nst = i + 1;
        
        if(nxt==tar)nxt=0,nc=nc+1,nst=1;
        if(tour(tar,idx+1,nxt,nc,nst))return true;
        
        used[i]=false;
        L=A[i];
        
        if(cur+A[i]==tar)return false;
    }
    return false;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >>n;
    for(int i =1; i <= n; i++){
        cin>>A[i];
        sum+=A[i];
        mx=max(mx,A[i]);
    }
    sort(A+1,A+1+n);
    reverse(A+1,A+1+n);
    for(int i = mx; i<= sum;i++){
        if(sum%i!=0)continue;
        
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(A[j]>i/2) cnt++;
        }
        if(cnt>sum/i) continue;

        if(tour(i,1,0,0,1)){
            for(int j=1;j<=n;j++){
                ret[group[j]].push_back(A[j]);
            }
            cout<<i<<"\n";
            for(int j=0;j<sum/i;j++){
                for(auto x:ret[j]) cout<<x<<' ';
                cout<<"\n";
            }
            return 0;
        }
    }
}
