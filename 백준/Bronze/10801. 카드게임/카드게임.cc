#include <bits/stdc++.h>

using namespace std;

int a[15], b[15];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for(int i = 1; i <= 10; i++) cin >> a[i];
    for(int i = 1; i <= 10; i++) cin >> b[i];

    int A = 0, B = 0;

    for(int i = 1; i <= 10; i++){
        if(a[i] > b[i]) A++;
        else if(a[i] < b[i]) B++;
    }

    if(A > B) cout << 'A';
    else if(A < B) cout << 'B';
    else cout << 'D';

    return 0;
}
