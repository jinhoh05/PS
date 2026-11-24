#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e7;

int n;
int poly[105][105];

int polyomino(int p, int first){
    if(p == first) return 1;


    int &ret = poly[p][first];
    if(ret != -1) return ret;
    ret = 0;

    for(int i=1; i<=p-first; i++){
        int cnt = i+first-1;

        cnt *= polyomino(p-first, i);
        cnt %= MOD;

        ret += cnt;
        ret %= MOD;
    }

    return ret;
}

int main()
{
    scanf("%d", &n);
    while(n--){
        memset(poly, -1, sizeof(poly));

        int p;
        scanf("%d", &p);

        int ans=0;
        for(int i=1; i<=p; i++){
            ans += polyomino(p, i);
            ans %= MOD;
        }

        printf("%d\n", ans);
    }

    return 0;
}
