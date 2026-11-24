#include <bits/stdc++.h>

using namespace std;

/// 강연결 요소 : scc
/// 단순 개념 : 사이클 덩어리
/// 정의 : 강연결요소에  속하는 어떤 두 정점을 고라도 서로 갈 수 있는 경로 존재
/// 사이클 없는 방향 그래프 : DAG

int n, m, s, e, cnt, ans, num, famous;
int group[10005], vt[10005], point[10005], me[10005];
stack<int> stk;
queue<int> q;
vector<int> v[10005], r_v[10005], List[10005];

void dfs(int x){
    if(vt[x]) return;
    vt[x] = 1;

    for(int u : v[x]) dfs(u);
    stk.push(x);
}

void r_dfs(int x){
    if(vt[x]) return;
    vt[x] = cnt;

    me[x] = cnt;
    List[cnt].push_back(x);

    for(int u : r_v[x]) r_dfs(u);
}

void scc(){
    for(int i=1;i<=n;i++){
        if(!vt[i]) dfs(i);
    }
    memset(vt, 0, sizeof(vt));

    while(!stk.empty()){
        int x = stk.top();
        stk.pop();

        if(vt[x]) continue;

        cnt++;
        r_dfs(x);
    }
}

void find_topol(int x){
    for(int u : v[x]){
        if(me[x] != me[u]){
            point[me[x]]++;
        }
    }
}

void topol(){
    for(int i=1;i<=n;i++){
        find_topol(i);
    }

    for(int i=1;i<=cnt;i++){
        if(!point[i]){
            famous++;
            num = i;
        }
    }

    if(famous != 1) printf("0");
    else printf("%d", List[num].size());
}

void input(){
    scanf("%d %d", &n, &m);

    for(int i=0;i<m;i++){
        scanf("%d %d", &s, &e);
        v[s].push_back(e);
        r_v[e].push_back(s);
    }
}

int main()
{
    input();

    scc();

    topol();

    return 0;
}