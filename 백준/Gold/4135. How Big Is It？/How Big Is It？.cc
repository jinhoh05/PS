#include <bits/stdc++.h>
 
using namespace std;
 
int T, M;
 
double ans = 1e9;
double r[10], p[10];
 
int main()
{
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%d", &M);
 
        for(int i = 0; i < M; i++)
        {
            scanf("%lf", &r[i]);
        }
 
        sort(r, r + M);
        
        ans = 1e9;
 
        do{
            p[0] = r[0];
            double val = 2 * r[0];
 
            for(int i = 1; i < M; i++)
            {
                p[i] = r[i];
 
                for(int j = 0; j < i; j++)
                {
                    p[i] = max(p[i], p[j] + 2 * sqrt(r[i] * r[j]));
                }
 
                val = max(val, p[i] + r[i]);
            }
 
            ans = min(ans, val);
 
        } while(next_permutation(r, r + M));
 
        printf("%.3f\n", ans);
    }
    
    return 0;
}