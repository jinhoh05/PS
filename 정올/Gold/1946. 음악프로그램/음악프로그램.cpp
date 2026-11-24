#include <bits/stdc++.h>

using namespace std;
int n, m, k, val1, val2, cnt, num;
int point[1005], vt[1005][1005], ans[1005];
vector<int> v[1005];
queue<int> q;

void push(int x){
    for(int u : v[x]){
        point[u]--;
        if(point[u] == 0) q.push(u);
    }
}

void topol(){
    while(!q.empty()){
        int t = q.front();
        q.pop();

        ans[++cnt] = t;
        push(t);
    }

    if(cnt != n) printf("0");
    else{
        for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    }
}

void input(){
    scanf("%d %d", &n, &m);

    for(int i=1;i<=m;i++){
        scanf("%d %d", &k, &val2);

        for(int j=2;j<=k;j++){
            scanf("%d", &num);
            val1 = num;

            v[val2].push_back(val1);
            point[val1]++;

            val2 = val1;
        }
    }
}

int main()
{
    input();

    for(int i=1;i<=n;i++){
        if(point[i] == 0){
            point[i]--;
            q.push(i);
        }
    }

    topol();

    return 0;
}