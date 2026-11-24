#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, mx;
int arr[20005];

ll ans = 0;

struct data
{
    int x, y1, y2, vt;

    bool operator<(const data &t)const
    {
        if(x == t.x) return vt < t.vt;
        else return x < t.x;
    }
};

vector<data> dot;

void rectangle()
{
    for(data t : dot)
    {
        int cnt = 0;

        for(int i = 0; i <= 20000; i++)
        {
            if(arr[i] > 0) cnt++;
        }

        ans += cnt * (t.x - mx);

        for(int i = t.y1 + 1; i <= t.y2; i++)
        {
            if(t.vt == 1) arr[i]++;
            else arr[i]--;
        }

        mx = t.x;
    }
}

void input()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        double a, b, c, d;

        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

        a *= 10, b *= 10, c *= 10, d *= 10;

        dot.push_back({a, b, b + d, 1});
        dot.push_back({a + c, b, b + d, -1});
    }

    sort(dot.begin(), dot.end());
}

int main()
{
    input();

    rectangle();

    if(ans % 100 == 0) printf("%lld", ans / 100);
    else printf("%.2f", ans / 100.0);

    return 0;
}