#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, c, n, m;
    cin >> a >> b >> c >> n >> m;

    long long r = c - a * b , cnt = 0;
    if (r >= 0) cout << m - n + 1 << "\n" << 0;
    else {
        r *= -1;
        long long dif, s, neg, pos;
        for (int i = 1; i <= b; i++) {
            dif = c - a * i;
            if (dif < 0) cnt += (m / b + ((m % b) >= i)) - (n / b + ((n % b) > i)) + ((n % b) == 0 && (i % b) == 0);
            else {
                s = (dif / r + 1) * b + i;
                if (s > m) continue;
                if (n >= s) neg = n / b - ((n % b) == 0 && (s % b) == 0) + ((n % b) > i);
                else neg = s / b - ((s % b) == 0);
                pos = m / b + ((m % b) >= i);
                cnt += pos - neg;
            }
        }
        cout << m - n + 1 - cnt << "\n" << cnt;
    }
}