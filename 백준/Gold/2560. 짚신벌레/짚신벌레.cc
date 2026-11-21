#include <bits/stdc++.h>
 
using namespace std;

int k, num;
int a, b, d, n;
int cnt = 2, grow = 1;
int bug[10005];
 
int main()
{
    scanf("%d %d %d %d", &a, &b, &d, &n);
 
    bug[1] = bug[a + 1] = 1;
    k = a + 2;
 
    for(int i = a + 2; i <= n + 1; i++)
    {
        if(k > d) k = 1;
 
        if(i > d)
        {
            cnt -= bug[k] % 1000;
            bug[k] = 0;
        }
 
        if(k > a)
        {
            grow += bug[k - a] % 1000;
        }
        
        else
        {
            grow += bug[d - (a - k)] % 1000;
        }
        
        if(k > b && i >= b)
        {
            grow-=bug[k-b] % 1000;
        }
 
        else if(k <= b && i >= b)
        {
            grow -= bug[d - (b - k)] % 1000;
        }
 
        bug[k++] = grow % 1000;
        cnt += grow % 1000;
    }
 
    printf("%d",cnt % 1000);
 
    return 0;
}