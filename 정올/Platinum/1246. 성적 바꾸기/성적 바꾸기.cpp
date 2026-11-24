#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, K, cnt;

double l = 0, r = 100;
double P;

///a - b * avg;

ll a[1005], b[1005];
ll a_hap, b_hap;

double avg[1005];

int main()
{
    scanf("%d %d", &N, &K);

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

    printf("%.f", P);

    return 0;
}
