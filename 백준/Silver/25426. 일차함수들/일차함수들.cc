#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
int func[100005];

ll ans;

int main(){

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        int b;
        scanf("%d %d", &func[i], &b);
        ans += b;
    }

    sort(func + 1, func + n + 1);

    for(int i=1; i<=n; i++) ans += (ll)func[i] * i;

    printf("%lld", ans);

    return 0;
}
