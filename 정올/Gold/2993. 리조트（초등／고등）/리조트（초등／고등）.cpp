#include <bits/stdc++.h>

using namespace std;
const int INF=0x0f0f0f0f;
int n,m,black[105],DP[105][105];

int dynamic(int now,int cp){
    if(now > n) return 0;
    if(DP[now][cp] != INF) return DP[now][cp];
    if(black[now]) return DP[now][cp] = dynamic(now+1,cp);

    int &ret=DP[now][cp];
    ret = min(ret, dynamic(now + 1, cp) + 10000);
    ret = min(ret, dynamic(now + 3, cp + 1) + 25000);
    ret = min(ret, dynamic(now + 5, cp + 2) + 37000);

    if(cp >= 3) ret = min(ret, dynamic(now + 1, cp - 3));

    return ret;
}

int main()
{
    memset(DP,15,sizeof(DP));

    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int a;
        scanf("%d",&a);
        black[a]=1;
    }

    printf("%d",dynamic(1,0));

    return 0;
}