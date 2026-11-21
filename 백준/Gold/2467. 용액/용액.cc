#include <bits/stdc++.h>

using namespace std;

int n;
int a, b, sum, val;
int koi[100005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    int l = 1, r = n;

    for(int i=1;i<=n;i++) cin >> koi[i];

    val = abs(koi[1] + koi[n]) + 1;

    while(l < r){
        sum = koi[l] + koi[r];
        if(abs(sum) < val){
            val = abs(sum);
            a = koi[l];
            b = koi[r];
        }

        if(sum < 0) l++;
        else r--;
    }

    cout << a  << " " << b;

    return 0;
}
