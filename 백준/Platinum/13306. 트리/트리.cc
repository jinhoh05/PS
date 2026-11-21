#include <bits/stdc++.h>
 
using namespace std;
 
int n, q;
int ver[200005], G[200005], l[200005];
int query[400005][3];
stack<int> stk;
 
void init(){
    for(int i=0;i<=200000;i++){
        G[i] = i;
        l[i] = 1;
    }
}
 
int union_p(int x){
    if(x == G[x]) return x;
    return G[x] = union_p(G[x]);
}
 
void find_p(int a, int b){
    a = union_p(a);
    b = union_p(b);
 
    if(a == b) return;
 
    if(l[a] > l[b]) swap(a, b);
    G[a] = b;
    if(l[a] == l[b]) l[b]++;
}
 
void find_ans(int i){
    if(query[i][2]){
        if(union_p(query[i][1]) == union_p(query[i][2])) stk.push(1);
        else stk.push(0);
    }
 
    else find_p(query[i][1], ver[query[i][1]]);
}
 
void input(){
    scanf("%d %d", &n, &q);
 
    ver[1] = 1;
 
    for(int i=2;i<=n;i++){
        int a;
        scanf("%d", &a);
        ver[i] = a;
    }
 
    q += (n - 2);
 
    for(int i=0;i<=q;i++){
        int x;
        scanf("%d", &x);
 
        if(x) scanf("%d %d", &query[i][1], &query[i][2]);
        else{
            scanf("%d", &query[i][1]);
            query[i][2] = 0;
        }
    }
}
 
int main()
{
    input();
 
    init();
 
    for(int i=q;i>=0;i--) find_ans(i);
 
    while(!stk.empty()){
        printf("%s\n", stk.top() ? "YES" : "NO");
        stk.pop();
    }
 
    return 0;
}