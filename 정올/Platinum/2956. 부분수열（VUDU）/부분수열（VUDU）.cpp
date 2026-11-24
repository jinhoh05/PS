#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pli = pair<ll, int>;

const int LN = 1e6 + 10;

int N, P;

ll ans;
ll A[LN], tree[LN];

vector<pli> v;

void update(int x){
    for(x++; x<LN; x+=x&-x) tree[x]++;
}

ll query(int x){
    ll sum=0;
    for(; x; x-=x&-x) sum += tree[x];
    return sum;
}

int main()
{
    scanf("%d", &N);

    for(int i=1; i<=N; i++){
        scanf("%lld", &A[i]);
    }

    scanf("%d", &P);

    for(int i=1; i<=N; i++) A[i] -= P;

    for(int i=1; i<=N; i++){
        A[i] += A[i - 1];
        v.push_back({A[i], i});
    }

    v.push_back({0, 0});
    sort(v.begin(), v.end());

    for(int i=0; i<=N; i++){
        ans += query(v[i].second);
        update(v[i].second);
    }

    printf("%lld", ans);

    return 0;
}
