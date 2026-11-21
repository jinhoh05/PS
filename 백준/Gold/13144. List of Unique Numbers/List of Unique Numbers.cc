#include <bits/stdc++.h>

using namespace std;

int N;
int seq[100005];
int vt[100005];
int val, l, r;

long long ans;

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &seq[i]);
    }

    while(r < N)
    {
        int val = seq[r];

        while(vt[val])
        {
            ans += (r - l);
            vt[seq[l++]] = 0;
        }

        vt[val] = 1;
        r++;
    }

    ans += (long long)(r - l) * (r - l + 1) / 2;

    printf("%lld", ans);

    return 0;
}
