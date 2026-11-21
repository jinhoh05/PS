#include <bits/stdc++.h>

int n, m;
int a[100001];

bool f(double x) 
{
    double sl = 0, sr = 0, mini = 0;
    for (int i = 1; i < m; i++) sr += a[i] - x;
    for (int i = m; i <= n; i++) {
        sr += a[i] - x;
        if (sl < mini) mini = sl;
        if (sr >= mini) return true;
        sl += a[i - m + 1] - x;
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    double low = 0, up = 2000, mid;
    for (int i = 0; i < 100; i++) {
        mid = (low + up) / 2;
        f(mid) ? low = mid : up = mid;
    }
    printf("%d", int(mid * 1000 + 1e-6));

    return 0;
}