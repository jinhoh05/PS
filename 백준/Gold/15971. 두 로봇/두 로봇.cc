#include <bits/stdc++.h>
 
using namespace std;
 
const int num=100005;
int n,r1,r2;
vector<pair<int,int>> v[num];
int dist[num],chk[num],maxi[num];
 
void dfs(int u,int d,int big){
    dist[u]=d;
    maxi[u]=big;
    chk[u]=1;
 
    for(auto i : v[u]){
        if(!chk[i.first]) dfs(i.first,d+i.second,max(big,i.second));
    }
}
 
int main()
{
    scanf("%d %d %d",&n,&r1,&r2);
    for(int i=1;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
 
    if(r1 == r2) {
        printf("0");
        return 0;
    }
    dfs(r1,0,0);
 
    printf("%d",dist[r2]-maxi[r2]);
 
    return 0;
}