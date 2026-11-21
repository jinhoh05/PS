#include <bits/stdc++.h>

using namespace std;

int n, value, from;
int x[105];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=0;i<n;i++){
        int num;
        cin >> num;

        from = (from + value) % n;
        value = x[from];

        while(value > 0){
            from = (from + 1) % n;
            value = x[from];
        }

        x[from] = num;
        value = num;
    }

    cout << n << "\n";

    for(int i=0;i<n;i++) cout << x[i] << " ";

    return 0;
}
