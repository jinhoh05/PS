#include <bits/stdc++.h>

using namespace std;

int n, m;
int A[100005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) cin >> A[i];

    sort(A, A + n);

    cin >> m;
    for(int i=1;i<=m;i++){
        int x;
        cin >> x;

        if(binary_search(A, A + n, x)) cout << '1' << "\n";
        else cout << '0' << "\n";
    }

    return 0;
}
