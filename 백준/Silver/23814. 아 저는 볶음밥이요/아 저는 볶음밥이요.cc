#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll D, answer;
ll N,M,K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> D >> N >> M >> K;

    ll ans = (N + M + K) / D;

    ll cnt = 0;

    cnt += N / D;
    cnt += M / D;
    cnt += K / D;

    if(cnt == ans)
    {
        cout << K;
        return 0;
    }
    
    ll val1 = D - (N % D);
    ll val2 = D - (M % D);

    if(K >= min(val1, val2))
    {
        cnt = 1 + (N / D) + (M / D) + (K - min(val1, val2)) / D;
    }
    
    if(cnt == ans)
    {
        cout << K - min(val1, val2);
        return 0;
    }

    if(K >= val1 + val2)
    {
        cnt = 2 + (N / D) + (M / D) + (K - val1 - val2) / D;
    }
    
    if(cnt == ans)
    {
        cout << K - val1 - val2;
        return 0;
    }
    
    if(K < min(val1, val2))
    {
        cnt = (N / D) + (M / D) + K / D;
    }
    
    if(cnt == ans)
    {
        cout << K;
        return 0;
    }

    return 0;
}
