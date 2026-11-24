#include <bits/stdc++.h>

using namespace std;
int n, m;
long long ans;
struct data{
    int x, y, vt;
    bool operator<(const data& t)const{
        if(y == t.y) return x < t.x;
        return y > t.y;
    }
};
data cow[100005], grass[100005];

multiset<int> st;

void input(){
    scanf("%d %d",&n, &m);
    for(int i=1;i<=n;i++) scanf("%d %d",&cow[i].x, &cow[i].y);
    for(int i=1;i<=m;i++) scanf("%d %d",&grass[i].x, &grass[i].y);

    sort(cow+1, cow+n+1);
    sort(grass+1, grass+m+1);
}

int compare(){
    int j=1;
    for(int i=1;i<=n;i++){
        for(;j<=m && grass[j].y >= cow[i].y;j++) st.insert(grass[j].x);
        auto q = st.lower_bound(cow[i].x);
        if(q == st.end()) return 0;
        ans += (*q);
        st.erase(q);
    }

    return 1;
}

int main()
{
    input();

    if(compare()) printf("%lld",ans);
    else printf("-1");

    return 0;
}