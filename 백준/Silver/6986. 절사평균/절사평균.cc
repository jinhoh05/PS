#include <bits/stdc++.h>

using namespace std;

double a;

vector<int> v;

void output(int ans, int k){
    ans /= k;
    if(ans % 10 >= 5) ans += 10;
    ans /= 10;

    cout << ans / 100 << '.' << (ans / 10) % 10 << ans % 10 << "\n";
}

int main()
{
    int n, k, ans1 = 0, ans2 = 0;

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(1000 * a);
    }

    sort(v.begin(), v.end());

    for(int i=k;i<n-k;i++) ans1 += v[i];

    ans2 = ans1 + k * (v[k] + v[n - k - 1]);

    output(ans1, n - (2 * k));
    output(ans2, n);

    return 0;
}
