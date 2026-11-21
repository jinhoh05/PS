#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, M;
ll score, val = 1LL << 60;

vector<ll> A, B;

bool check(ll x)
{
    ll day = 0;

    for(ll i = 0; i < N; i++)
    {
        if(x <= A[i] * M) day += (x + A[i] - 1) / A[i];
        else day += M + (x - (A[i] * M) + B[i] - 1) / B[i];

        if(day > N * M) return false;
    }

    return true;
}

void input()
{
    ll x;
    
    scanf("%lld %lld", &N, &M);

    for(ll i = 0; i < N; i++)
    {
        scanf("%lld", &x);
        A.push_back(x);
    }

    for(ll i = 0; i < N; i++)
    {
        scanf("%lld", &x);
        B.push_back(x);
    }
}

int main()
{
    input();

    for(ll i = 0; i < N; i++) A[i] = max(A[i], B[i]);

    while(val - score > 1)
    {
        ll mid = (val + score) / 2;

        if(check(mid)) score = mid;
        else val = mid;
    }

    printf("%lld", score);

    return 0;
}
