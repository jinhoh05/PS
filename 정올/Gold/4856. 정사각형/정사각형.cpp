#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, ans;
int x[3005], y[3005];

set<pii> st;

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        st.insert({x[i], y[i]});
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1, p, q, r, s; j < N; j++)
        {
            p = x[i] + x[j];
            q = y[i] + y[j];

            r = x[i] - x[j];
            s = y[i] - y[j];

            if(abs(p - q) & 1) continue;

            if(st.find({(p + s) / 2, (q - r) / 2}) != st.end())
            {
                if(st.find({(p - s) / 2, (q + r) / 2}) != st.end())
                {
                    ans = max(ans, (r * r + s * s) / 2);
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}
