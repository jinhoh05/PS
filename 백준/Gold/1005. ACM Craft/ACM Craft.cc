#include <bits/stdc++.h>

using namespace std;
int t, n, k, w;
int point[1005], Time[1005], r_time[1005];

vector<int> v[1005];
queue<int> q;

void RESET(){
    for(int i=1;i<=n;i++){
        v[i].clear();
        point[i] = Time[i] = r_time[i] = 0;
    }
    while(!q.empty()) q.pop();
}

void topol(){
    for(int i=1;i<=n;i++){
        if(!point[i]) q.push(i);
    }

    while(point[w] > 0){
        int t = q.front();
        q.pop();
        for(int u : v[t]){
            r_time[u] = max(r_time[u], r_time[t]+Time[t]);
            if(--point[u] == 0) q.push(u);
        }
    }

    printf("%d\n", r_time[w] + Time[w]);
}

void input(){
    scanf("%d %d", &n, &k);

    for(int i=1;i<=n;i++) scanf("%d", &Time[i]);

    for(int i=1;i<=k;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        point[y]++;
    }

    scanf("%d", &w);
}

int main(){

    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        input();
        topol();
        RESET();
    }

    return 0;
}
