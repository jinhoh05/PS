#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> v;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    v.resize(n);

    for(int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(), v.end());

    if(v[0] != 1) cout << 1;

    else{
        int sum = 1;

        for(int i=1;i<n;i++){
            if(v[i] > sum + 1) break;
            sum += v[i];
        }

        cout << sum + 1;
    }

    return 0;
}
