#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct water
{
    int y1, y2;
    int wh[2];
};

water obj[100005];

int n, m;

void calc_wh(int s, int e, int d, int t)
{
    int val = n + 1;
    
    for(int i = s; i != e; i += d)
    {
        if(t != 0 || obj[i].y2 >= n)
            val = min(val, obj[i].y1);   
        
        obj[i].wh[t] = max(val, obj[i].wh[t]);
    }
}

void calc_wh2()
{
    for(int s = 0; s < m;)
    {
        if(obj[s].y2 < n)
        {
            int e = s + 1;
            
            for(; e < m; e++)
            {
                if(obj[e].y1 > obj[e - 1].y2 || obj[e].y2 < obj[e - 1].y1) break;
            }
            
            calc_wh(s, e, 1, 1);
            calc_wh(e - 1, s - 1, -1, 1);
            
            s = e;
        }
        
        else s++;
    }
}

void output()
{
    ll cnt = 0;
    
    for(int i = 0; i < m; i++)
    {   
        if(obj[i].y2 >= n) cnt += obj[i].y1 - obj[i].wh[0];
      
        else
        {
            cnt += obj[i].y1 - obj[i].wh[1];
            
            int wh = max(obj[i].wh[0], obj[i].wh[1]);
            
            if(wh <= obj[i].y2) cnt += n + 1 - obj[i].wh[0] - (obj[i].y2 - wh + 1);
            else cnt += n + 1 - obj[i].wh[0];
        }
    }

    printf("%lld", cnt);
}

void input()
{
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &obj[i].y1, &obj[i].y2);
        
        if(obj[i].y2 == 0) obj[i].y1 = obj[i].y2 = n + 1;
    }
}

int main()
{
    input();
    
    calc_wh(0, m, 1, 0);
    calc_wh(m - 1, -1, -1, 0);
    calc_wh2();
    
    output();
    
    return 0;
}