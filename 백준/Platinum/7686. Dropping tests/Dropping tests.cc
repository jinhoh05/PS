#include <bits/stdc++.h>

using namespace std;
using ll = long long;

///a - b * avg;

int main()
{
    while(1)
    {
        int N, K, cnt = 0;
        
        ll a[1005] = {0,}, b[1005] = {0,};
        ll a_hap = 0, b_hap = 0;
        
        double l = 0, r = 100;
        double P;
        double avg[1005] = {0,};
        
        scanf("%d %d", &N, &K);

        if(N == 0 && K == 0) break;
        
        for(int i = 1; i <= N; i++)
        {
            scanf("%lld", &a[i]);
        }

        for(int i = 1; i <= N; i++)
        {
            scanf("%lld", &b[i]);
        }

        for(int j = 1; j <= 50; j++)
        {
            P = (l + r) / 2;

            for(int i = 1; i <= N; i++)
            {
                avg[i] = a[i] - b[i] * (P / 100);
            }

            sort(avg + 1, avg + N + 1);

            double hap = 0;

            for(int i = K + 1; i <= N; i++)
            {
                hap += avg[i];
            }

            if(hap < 0) r = P;
            else l = P;
        }

        printf("%.f\n", P);

    }
    
    return 0;
}
