#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> p[100005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> p[i].first >> p[i].second;

    sort(p + 1, p + n + 1);

    for(int i=1;i<=n;i++) cout << p[i].first << " " << p[i].second << "\n";

    return 0;
}
