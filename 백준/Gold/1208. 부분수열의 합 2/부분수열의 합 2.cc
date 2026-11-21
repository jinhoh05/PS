#include <bits/stdc++.h>

using namespace std;

int N, S;
int arr[50];

long long ans;

map<int, int> mp;

void left(int idx, int sum)
{
    if(idx == N / 2)
    {
        mp[sum]++;
        return;
    }

    left(idx + 1, sum);
    left(idx + 1, sum + arr[idx]);
}

void right(int idx, int sum)
{
    if(idx == N)
    {
        ans += mp[S - sum];
        return;
    }

    right(idx + 1, sum);
    right(idx + 1, sum + arr[idx]);
}

int main()
{
    scanf("%d %d", &N, &S);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    left(0, 0);
    right(N / 2, 0);

    if(S == 0) ans -= 1;

    printf("%lld", ans);

    return 0;
}
