#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, p, l, ans, cnt;

pii fuel[10005];

priority_queue<int> pq;

void bfs(){
    while(p < l){
        while(cnt < n && p >= fuel[cnt].first){
            pq.push(fuel[cnt++].second);
        }
        
        if(pq.empty()){
            ans=-1;
            return;
        }
        
        p += pq.top();
        pq.pop();
        ans++;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &fuel[i].first, &fuel[i].second);
    }
    scanf("%d %d", &l, &p);
    
    sort(fuel, fuel+n);
    
    bfs();

    printf("%d", ans);

    return 0;
}