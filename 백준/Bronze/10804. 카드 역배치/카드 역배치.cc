#include <bits/stdc++.h>

using namespace std;

int a, b;
vector<int> arr(21);

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for(int i = 1; i <= 20; i++) arr[i] = i;

    for(int i = 1; i <= 10; i++){
        cin >> a >> b;
        reverse(arr.begin() + a, arr.begin() + b + 1);
    }

    for(int i = 1; i <= 20; i++) cout << arr[i] << " ";

    return 0;
}
