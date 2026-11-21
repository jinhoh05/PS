#include <bits/stdc++.h>
 
using namespace std;
 
int c, n;
int kiwi[16];
int cost[1000005];
int DP[1 << 15];
 
int calc(int sum, int cnt)
{
    int val = cost[c] * (sum / c);
    cnt -= sum / c;
    sum %= c;
 
    if(cnt == 0) return val;
 
    else
    {
        val += cost[sum];
        sum = 0;
 
        if(cnt > 0) val += cost[0] * (cnt - 1);
    }
 
    return val;
}
 
 
int kiwi_juice()
{
    for(int i = 0; i < n; i++) DP[(1 << i)] = cost[kiwi[i]];
 
    int m = (1 << n);
 
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j <= i / 2; j++)
        {
            if((i | j) > i) continue;
 
            DP[i] = max(DP[i], DP[j] + DP[i - j]);
        }
 
        int sum = 0, cnt = 0;
 
        for(int k = 0; k < n; k++)
        {
            if((i & (1 << k)))
            {
                sum += kiwi[k];
                cnt++;
            }
        }
 
        DP[i] = max(DP[i], calc(sum, cnt));
    }
 
    return DP[m - 1];
}
 
void input()
{
    scanf("%d %d", &n, &c);
 
    for(int i = 0; i < n; i++)
        scanf("%d", &kiwi[i]);
 
    for(int i = 0; i <= c; i++)
        scanf("%d", &cost[i]);
 
}
 
int main()
{
    input();
 
    printf("%d", kiwi_juice());
 
    return 0;
}