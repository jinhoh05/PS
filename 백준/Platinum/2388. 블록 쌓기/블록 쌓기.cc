#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[5005], b[5005], c[5005], d[5005];
int ans1, ans2;
int w, h;

int main()
{
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);

        a[num]++;
        ans1 += num;
        ans2 += num * M;

        if(num > w) w = num;
    }

    for(int i = 5000; i >= 0; i--)
    {
        c[i] = c[i + 1] + a[i + 1];
        b[i] = b[i + 1] + a[i + 1] * (i + 1);
    }

    for(int i = 5000; i >= 0; i--)
    {
        b[i] = b[i] - c[i] * i;
    }

    for(int i = 0; i < M; i++)
    {
        int num;
        scanf("%d", &num);

        if(a[num]) --a[num];
        else ans1 += num;
        ans2 -= b[num];

        if(num > h) h = num;
    }

    if(w == h) printf("%d %d", ans1, ans2);
    else printf("-1");

    return 0;
}
