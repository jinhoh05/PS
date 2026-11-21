#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n;
int G[305];

struct Data{

    int a, b, m;

    bool operator<(const Data &t)const{
        return m < t.m;
    }

} v[60005];

int find_p(int x){
    if(G[x] == x) return x;
    return G[x] = find_p(G[x]);
}

void union_find(int a, int b){
    G[a] = b;
}

int main()
{
    scanf("%d", &n);

    for(int i=0; i<=n; i++) G[i]=i;

    int u=0;
    for(int i=1; i<=n; i++){
        scanf("%d", &v[u].m);
        v[u].a=0;
        v[u++].b=i;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            scanf("%d", &x);

            if(i < j){
                v[u].a=i;
                v[u].b=j;
                v[u++].m=x;
            }
        }
    }

    sort(v, v+u);

    int sum=0, l, r;
    for(int i=0; i<u; i++){
        l = find_p(v[i].a);
        r = find_p(v[i].b);

        if(l != r){
            union_find(l, r);
            sum += v[i].m;
        }
    }

    printf("%d", sum);

    return 0;
}
