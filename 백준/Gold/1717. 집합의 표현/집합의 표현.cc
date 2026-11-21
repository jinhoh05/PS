
#include <bits/stdc++.h>

using namespace std;
int n, m, ans;
int G[1000005];

int get_p(int x){
    if(G[x] == x) return x;
    return G[x]=get_p(G[x]);
}

void union_p(int s,int e){
    s = get_p(s);
    e = get_p(e);
    if(s < e) G[e]=s;
    else G[s]=e;
}

int find_p(int s,int e){
    s = get_p(s);
    e = get_p(e);

    if(s == e) return 1;
    else return 0;
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++) G[i]=i;

    for(int i=1;i<=m;i++){
        int num, s, e, check;
        scanf("%d %d %d", &num, &s,&e);

        if(num == 0) union_p(s, e);
        else if(find_p(s,e)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
