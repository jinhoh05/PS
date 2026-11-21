#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

int n, t, x[3005], y[3005];

int main() {
    scanf("%d", &t);
    while (t--) {
        int res = 0;
        set<pair<int, int> > st;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d %d", x + i, y + i), st.insert({ x[i],y[i] });
        for (int i = 0; i < n; i++) {
            for (int j = i + 1, p, q, r, s; j < n; j++) {
                p = x[i] + x[j];
                q = y[i] + y[j];
                r = x[i] - x[j];
                s = y[i] - y[j];
                if (abs(p - q) & 1) continue;
                if (st.find({ (p + s) / 2,(q - r) / 2 }) != st.end() && st.find({ (p - s) / 2,(q + r) / 2 }) != st.end())
                    res = max(res, (r*r + s*s) / 2);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}