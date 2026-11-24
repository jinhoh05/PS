/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
  
using namespace std;
using ll = long long;
  
int T, N;
  
ll lz;
ll la[100005], lb[100005];
  
vector<ll> px, py, lx, ly;
  
double cross1(int a, int b)
{
    return double(px[a] + px[b] - py[a] + py[b]) / 2.0;
}
  
void Remove()
{
    stack<int> stk;
    stk.push(0);
  
    for(int next = 1; next < N; next++)
    {
        int now = stk.top();
        double xy = cross1(now, next);
  
        if(xy >= px[next])
        {
            while(xy >= px[next])
            {
                stk.pop();
  
                if(stk.empty()) break;
  
                now = stk.top();
                xy = cross1(now, next);
            }
  
            stk.push(next);
        }
  
        else if(xy <= px[now]) continue;
  
        else stk.push(next);
    }
  
    N = stk.size();
    lx.clear(), ly.clear();
    lx.resize(N), ly.resize(N);
  
    while(!stk.empty())
    {
        int top = stk.top(); stk.pop();
        lx.push_back(px[top]), ly.push_back(py[top]);
    }
  
    reverse(lx.begin(), lx.end());
    reverse(ly.begin(), ly.end());
}
  
void init()
{
    lz = 0;
    memset(la, 0, sizeof(la));
    memset(lb, 0, sizeof(lb));
}
  
double cross2(int x, int y)
{
    return (double)(lb[y] - lb[x]) / (la[x] - la[y]);
}
  
void in(ll a, ll b)
{
    la[lz] = a;
    lb[lz] = b;
  
    while(lz > 1 && cross2(lz - 2, lz - 1) > cross2(lz - 1, lz))
    {
        la[lz - 1] = la[lz];
        lb[lz - 1] = lb[lz];
        lz--;
    }
  
    lz++;
}
  
ll query(int x)
{
    int l = 0, h = lz - 1;
  
    while(l < h){
        int mid = (l + h) / 2;
        if(cross2(mid, mid + 1) <= x) l = mid + 1;
        else h = mid;
    }
  
    return la[l] * x + lb[l];
}
  
string val[4] = {".00", ".25", ".50", ".75"};
  
void light()
{
    vector<ll> DP(N + 1);
  
    in(-2 * (lx[0] - ly[0]), (lx[0] - ly[0]) * (lx[0] - ly[0]));
  
    for(int i = 0; i < N; i++)
    {
        ll u = lx[i] + ly[i];
        ll v = lx[i + 1] - ly[i + 1];
  
        DP[i] = query(u) + u * u;
  
        in(-2 * v, v * v + DP[i]);
    }
  
    cout << DP[N - 1] / 4 << val[DP[N - 1] % 4] << "\n";
}
  
void input()
{
    px.clear(), py.clear();
  
    scanf("%d", &N);
  
    px.resize(N), py.resize(N);
  
    for(int i = 0; i < N; i++)
        scanf("%lld %lld", &px[i], &py[i]);
}
  
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    scanf("%d", &T);
  
    for(int i = 1; i <= T; i++)
    {
        input();
  
        Remove();
  
        init();
  
        light();
    }
  
    return 0;
}