#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(!b) return a;
    if(a > b) return gcd(b, a % b);
    return gcd(a, b % a);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c, d;

    cin >> a >> b;
    b /= a;

    for(int i=1;i*i<=b;i++){
        if(b % i == 0){
            if(gcd(i, b / i) == 1){
                c = i;
                d = b / i;
            }
        }
    }

    cout << a * c << " " << a * d;

    return 0;
}
