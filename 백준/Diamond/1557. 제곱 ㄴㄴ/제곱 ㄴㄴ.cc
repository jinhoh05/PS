#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll K;
ll low, high;
ll mobius[1000001];

void buildMobius() {
    mobius[1] = 1;
   
    for(int i = 1; i <= 1000000; i++) 
    {
        if(mobius[i] != 0)
        {
            for(int j = 2 * i; j <=1000000; j += i) {
                mobius[j] -= mobius[i];
            }
        }
    }
}

ll squareFree(ll n)
{
    ll k = 0;
    
    for(ll i = 1; i*i <= n; i++)
    {
        k += (mobius[i]*(n/(i*i)));
    }
    
    return k;
}

int main() 
{
    low = 0;
    high = 2e9;
 
    scanf("%lld", &K);
    
    buildMobius();
    
    while(low + 1 < high)
    {
        ll mid = (low + high) / 2;
        
        if(squareFree(mid) < K) low = mid;
        else high = mid;
    }

    printf("%lld", high);

    return 0;
}