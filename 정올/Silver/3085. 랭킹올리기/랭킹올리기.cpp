#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> sc;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;

        sc.push_back(x);
    }

    sc.erase(unique(sc.begin(), sc.end()), sc.end());
    reverse(sc.begin(), sc.end());

    cin >> m;
    for(int i=0; i<m; i++){
        int num;
        cin >> num;

        int k = upper_bound(sc.begin(), sc.end(), num) - sc.begin();

        cout << sc.size() - k + 1 << endl;
    }

    return 0;
}