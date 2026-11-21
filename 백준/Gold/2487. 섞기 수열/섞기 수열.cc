#include <bits/stdc++.h>

using namespace std;

int n;
int a[20005], q[20005], vt[20005];

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> a[i];

    int now, cnt, sum;

    for(int i=1;i<=n;i++){
        sum = 1;
        now = cnt = a[i];

        if(vt[i] == 0){
            while(1){
                vt[now] = 1;
                now = a[now];

                if(now == cnt){
                    q[i] = sum;
                    break;
                }

                sum++;
            }
        }
    }

    int mx = q[1];
    for(int i=1;i<=n;i++){
        if(q[i] != 0) mx = mx / gcd(q[i], mx) * q[i];
    }

    cout << mx;

    return 0;
}
