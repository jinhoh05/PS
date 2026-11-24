#include <bits/stdc++.h>
 
using namespace std;
 
int N, M;
int ans;
int flower[300][300];
 
vector<int> v;
 
void calc(int val)
{
    int vt[63005] = {0};
 
    int x1 = 1, y1 = val, x2 = N, y2 = M - val + 1;
 
    if(val > M)
    {
        x1 += val - M;
        y1 = M;
 
        x2 -= val - M;
        y2 = 1;
    }
 
    while(x1 <= N && y1 >= 1)
    {
        vt[flower[x1][y1]]++;
        vt[flower[x2][y2]]++;
 
        if(x1 == x2 && y1 == y2)
        {
            vt[flower[x1][y1]]--;
            break;
        }
        
        if(x1 + 1 == x2 && y1 - 1 == y2) break;
 
        x1++, y1--;
        x2--, y2++;
    }
 
    int MAX = 0, k;
 
    for(int i = 1; i <= 63000; i++) MAX = max(MAX, vt[i]);
 
    for(int i = 1; i <= 63000; i++)
    {
        if(vt[i] == MAX)
        {
            k = i;
            break;
        }
    }
 
    for(int i = 1; i <= 63000; i++)
    {
        if(i != k) ans += vt[i];
    }
 
    //printf("%d %d %d\n", vt[1], vt[2], ans);
}
 
void compression()
{
    sort(v.begin(), v.end());
 
    v.erase(unique(v.begin(), v.end()), v.end());
 
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            for(int k = 0; k < v.size(); k++)
            {
                if(flower[i][j] == v[k])
                {
                    flower[i][j] = k + 1;
                    break;
                }
            }
        }
    }
}
 
int main()
{
    scanf("%d %d", &N, &M);
 
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            scanf("%d", &flower[i][j]);
 
            v.push_back(flower[i][j]);
        }
    }
 
    compression();
 
    for(int i = 1; i <= (N + M) / 2; i++)
    {
        calc(i);
    }
 
    printf("%d", ans);
 
    return 0;
}