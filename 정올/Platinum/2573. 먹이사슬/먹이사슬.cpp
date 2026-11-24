#include <bits/stdc++.h>

using namespace std;
int n,D[500000];
struct data{
    int l,r;

    bool operator<(const data&t)const{
        if(l==t.l) return r<t.r;
        return l>t.l;
    }
}ani[500000];

///조건 1: x1 < x3 && x2 > x4
///조건 2: x1 = x3 && x2 > x4
///조건 3: x1 < x3 && x2 = x4

int dynamic(){
    vector<int> v;

    for(int i=1;i<=n;i++){
        if(ani[i-1].l == ani[i].l && ani[i-1].r == ani[i].r) continue;

        auto it=upper_bound(v.begin(),v.end(),ani[i].r);

        if(it==v.end()) v.push_back(ani[i].r);
        else *it=ani[i].r;
    }

    return v.size();
}


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%*d %d %d",&ani[i].l,&ani[i].r);
    }

    sort(ani+1,ani+n+1);

    printf("%d",dynamic());

    return 0;
}