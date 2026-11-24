#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 2e5 + 5;
 
int n, q;
int color[MAX], parent[MAX];
int vcnt, visited[MAX];

vector<int> v[MAX];
 
struct data{
    int x, see;
};
 
void push_color(int b, int nowColor, int newColor)
{
    if(visited[b] == vcnt) return;
   
    color[b] = newColor;
   
    vector<int> &adj = v[b];
   
    int len = adj.size();
 
    for(int i = 0; i < len; i++)
    {
        int u = adj[i];
        
        if(color[u] == nowColor) push_color(u, nowColor, newColor);
    }
}
 
bool push(deque<data> &que, int now_color)
{
    while(!que.empty())
    {
        int x = que.front().x, &see = que.front().see;
 
        if(see >= (int)v[x].size())
        {
            visited[x] = vcnt;
            que.pop_front();
            continue;
        }
 
        if(visited[v[x][see]] == vcnt)
        {
            see++;
            continue;
        }
 
        if(now_color != color[v[x][see]])
        {
            swap(v[x][see], v[x].back());
            v[x].pop_back();
            continue;
        }
 
        visited[v[x][see]] = vcnt;
        que.push_back({v[x][see], 0});
        see++;
 
        return true;
    }
 
    return false;
}
 
bool multisource_bfs(int x, int y)
{
    deque<data> que1, que2;
 
    que1.push_back({x, 0});
    que2.push_back({y, 0});
 
    visited[x] = visited[y] = vcnt;
 
    while(1)
    {
        if(!push(que1, color[x])) return true;
        if(!push(que2, color[y])) return false;
 
        if(que1.empty()) return true;
        else if(que2.empty()) return false;
    }
 
    return false;
}
 
void check(int a, int i)
{
    int p = parent[a];
  
    if(p == a) return;
 
    int nowColor = color[a];
 
    if(multisource_bfs(a, p))
    {
        visited[p] = ++vcnt;
        push_color(a, nowColor, i + 1);
        parent[a] = a;
    }
 
    else
    {
        parent[a] = a;
        visited[a] = ++vcnt;
        push_color(p, nowColor, i + 1);
    }
 
    parent[a] = a;
}
 
void tree()
{
    for(int i = 0; i < q; i++)
    {
        vcnt++;
 
        int b, c, d;
 
        scanf("%d %d %d", &b, &c, &d);
        printf("%s\n", color[b] == color[c] ? "YES" : "NO");
 
        if(!d) continue;
 
        if(color[b] == color[c]) check(b, i);
        else check(c, i);
    }
}
 
void input()
{
    scanf("%d %d", &n, &q);
 
    parent[1] = 1;
 
    for(int i = 2; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
 
        parent[i] = x;
        v[i].push_back(x);
        v[x].push_back(i);
    }
} 
 
int main()
{
    input();
 
    tree();
  
    return 0;
}