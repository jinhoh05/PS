#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, cnt, ans;
vector<pii> v;

void meeting(){
    sort(v.begin(), v.end());

    for(pii u : v){
        cnt += u.second;
        ans = max(ans, cnt);
    }
}

void input(){
    scanf("%d", &n);

    for(int i=1;i<=n;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back({a, 1}),
        v.push_back({b, -1});
    }
}

int main()
{
    input();

    meeting();

    printf("%d", ans);
}
