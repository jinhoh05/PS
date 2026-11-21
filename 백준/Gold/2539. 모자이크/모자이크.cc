#include <bits/stdc++.h>

using namespace std;

int n, m, p, q;
int cnt, sum;
int a[1000005], b[1000005];

void check(){
    int w = 0;

    for(int i=sum;i<=n;i++){
        for(int j=1;j<=q;j++){
            if(w >= b[j]) continue;
            w = b[j] + i - 1;
            cnt++;
        }

        if(cnt <= p){
            cout << i;
            return;
        }

        w = cnt = 0;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> p >> q;

    for(int i=1;i<=q;i++){
        cin >> a[i] >> b[i];
        if(a[i] > sum) sum = a[i];
    }

    sort(b + 1, b + q + 1);

    check();

    return 0;
}
