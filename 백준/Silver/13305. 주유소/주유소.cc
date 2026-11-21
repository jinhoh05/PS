#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 100005;

int n;
ll sum;
ll dist[MAX], price[MAX], D[MAX];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1;i<n;i++) cin >> dist[i];
    for(int i=1;i<=n;i++) cin >> price[i];

    D[1] = price[1] * dist[1];
    sum = price[1];

    for(int i=2;i<=n;i++){
        if(price[i] < sum) sum = price[i];
        D[i] = D[i - 1] + sum * dist[i];
    }

    cout << D[n];

    return 0;
}
