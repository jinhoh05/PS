#include <bits/stdc++.h>

using namespace std;

int n, k;

struct st{
    int x, a, b, c;

    bool operator<(const st &t)const{
        if(a == t.a && b == t.b && c == t.c) return x == k;
        if(a == t.a && b == t.b) return c > t.c;
        if(a == t.a) return b > t.b;
        return a > t.a;
    }

}olympic[1005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for(int i=1;i<=n;i++){
        cin >> olympic[i].x >> olympic[i].a >> olympic[i].b >> olympic[i].c;
    }

    sort(olympic + 1, olympic + n + 1);

    for(int i=1;i<=n;i++){
        if(olympic[i].x == k){
            cout << i;
            return 0;
        }
    }

    return 0;
}
