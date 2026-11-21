#include <bits/stdc++.h>

using namespace std;

int n, m;
int point[32005];
vector<int> v[32005];
priority_queue<int> q;

void push(int x){
    for(int u : v[x]){
        point[u]--;
        if(point[u] == 0){
            q.push(-u);
        }
    }
}

void topol(){
    while(!q.empty()){
        int t = -q.top();
        q.pop();

        printf("%d ", t);

        push(t);
    }
}


void input(){
    scanf("%d %d", &n, &m);

    for(int i=1;i<=m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        point[b]++;
        v[a].push_back(b);
    }
}

int main()
{
    input();

    for(int i=1;i<=n;i++){
        if(!point[i]) q.push(-i);
    }

    topol();

    return 0;
}
