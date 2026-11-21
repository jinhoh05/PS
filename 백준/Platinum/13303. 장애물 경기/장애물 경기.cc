#include <bits/stdc++.h>
  
using namespace std;
using ll = long long;
  
int n, st_y, fin_x, cnt, longest, path_small=1e9;
int ans[100005], vt[100005];
  
struct data{
    int x, y1, yh;
    bool operator<(const data &t)const{
        return x == t.x ? y1 < t.y1 : x < t.x;
    }
}obs[100005];
  
struct st{
    int y, d;
    bool operator<(const st &t)const{
        return y < t.y;
    }
};
set<st> s;
  
int main()
{
    scanf("%d %d %d",&n, &st_y, &fin_x);
    s.insert({st_y, 0});
  
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&obs[i].x, &obs[i].y1, &obs[i].yh);
    }
    sort(obs + 1, obs + n + 1);
  
    for(int i=1;i<=n;i++){
        st a = {obs[i].y1,0}, b{obs[i].yh,0};
        int up=1e9, down=1e9;
  
        auto p = s.lower_bound(a);
        auto q = s.upper_bound(b);
  
        for(auto k=p;k!=q;k++){
            up=min(up, (k->d + (obs[i].yh - k->y)));
            down=min(down, (k->d + (k->y - obs[i].y1)));
        }
  
        s.erase(p, q);
  
        s.insert({obs[i].y1, down});
        s.insert({obs[i].yh, up});
    }
  
    int small=1e9;
    for(auto i:s) small=min(small,i.d);
    for(auto i:s){
        if(i.d == small) ans[++cnt]=i.y;
    }
    printf("%d\n%d ",small + fin_x, cnt);
  
    sort(ans+1, ans+cnt+1);
  
    for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);
  
  
    return 0;
}