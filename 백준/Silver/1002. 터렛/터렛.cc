#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

/// 두 점 사이의 거리 공식 : {(x1 - x2) ^ 2} + {(Y1 - y2) ^ 2} 의 루트값

int t;

ll x1, Y1, r1;
ll x2, y2, r2;
ll dx, dy;
ll add, sub;
ll d;

void output(){
    if(d < add && d > sub) cout << 2;

    else if(d == add || (d == sub && d != 0)) cout << 1;

    else if(d < sub || d > add) cout << 0;

    else if(d == 0){
        if(r1 == r2) cout << -1;

        else cout << 0;
    }

    cout << "\n";
}

void calc(){
    dx = x1 - x2;
    dy = Y1 - y2;

    if(r1 > r2) swap(r1, r2);

    add = r1 + r2;
    add *= add;

    sub = r1 - r2;
    sub *= sub;

    d = dx * dx + dy * dy;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--){
        x1 = x2 = Y1 = y2 = r1 = r2 = dx = dy = add = sub = d = 0;

        cin >> x1 >> Y1 >> r1 >> x2 >> y2 >> r2;

        calc();

        output();
    }

    return 0;
}
