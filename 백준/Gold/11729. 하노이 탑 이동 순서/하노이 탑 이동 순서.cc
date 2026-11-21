#include <bits/stdc++.h>

using namespace std;

int n, ans;

void hanoi(int x, int a, int b, int c){
    if(x == 1) cout << a << " " << c << "\n";

    else{
        hanoi(x - 1, a, c, b);
        cout << a << " " << c << "\n";
        hanoi(x - 1, b, a, c);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    cout << (1 << n) - 1 << "\n";

    hanoi(n, 1, 2, 3);

    return 0;
}
