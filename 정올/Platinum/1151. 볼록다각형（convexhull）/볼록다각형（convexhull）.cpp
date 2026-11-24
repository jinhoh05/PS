#include <bits/stdc++.h>
 
#define X first
#define Y second
 
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
 
int n;
 
pll dot[10005];
 
vector<int> v;
 
stack<int> stk;
 
int ccw(pll a, pll b, pll c)
{
    ll val = (c.Y - a.Y) * (b.X - a.X) - (b.Y - a.Y) * (c.X - a.X);
 
    return (val > 0) - (val < 0);
}
 
bool comp(pll a, pll b)
{
    return ccw(dot[0], a, b) > 0;
}
 
void geometry()
{
    int next = 2;
 
    stk.push(0);
    stk.push(1);
 
    while(next < n)
    {
        while(stk.size() >= 2)
        {
            int f, s;
            s = stk.top();
            stk.pop();
            f = stk.top();
 
            if(ccw(dot[f], dot[s], dot[next]) > 0)
            {
                stk.push(s);
                break;
            }
        }
 
        stk.push(next++);
    }
}
 
 
void output()
{
    ll ans, val1 = 0, val2 = 0;
 
    dot[n + 1] = dot[0];
 
    while(!stk.empty())
    {
        v.push_back(stk.top());
        stk.pop();
    }
 
    reverse(v.begin(), v.end());
 
    for(int i = 0; i < v.size(); i++)
        val1 += dot[v[i]].X * dot[v[i + 1]].Y;
 
 
    for(int i = 0; i < v.size(); i++)
        val2 += dot[v[i]].Y * dot[v[i + 1]].X;
 
    ans = abs(val1 - val2);
 
    printf("%lld", ans / 2);
 
    if(ans % 2 != 0) printf(".%d", 5);
}
 
 
void input()
{
    scanf("%d", &n);
 
    for(int i = 0; i < n; i++)
        scanf("%lld %lld", &dot[i].X, &dot[i].Y);
}
 
int main()
{
    input();
 
    sort(dot, dot + n);
    sort(dot + 1, dot + n, comp);
 
    geometry();
 
    output();
 
    /*while(!stk.empty())
    {
        printf("%d ", stk.top());
        stk.pop();
    }*/
 
    //printf("%d", (int)stk.size());
 
    return 0;
}