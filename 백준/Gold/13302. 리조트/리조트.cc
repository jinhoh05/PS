#include <bits/stdc++.h>

using namespace std;

const int INF = 0x0f0f0f0f;

int n, m;
int black[105];
int DP[105][105];

int dynamic(int now, int cp){
    if(now > n) return 0;
    if(DP[now][cp] != INF) return DP[now][cp];
    if(black[now]) return DP[now][cp] = dynamic(now + 1, cp);

    int &temp = DP[now][cp];
    temp = min(temp, dynamic(now + 1, cp) + 10000);
    temp = min(temp, dynamic(now + 3, cp + 1) + 25000);
    temp = min(temp, dynamic(now + 5, cp + 2) + 37000);

    if(cp >= 3) temp = min(temp, dynamic(now + 1, cp - 3));

    return temp;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    memset(DP, 15, sizeof(DP));

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a;
        cin >> a;
        black[a] = 1;
    }

    cout << dynamic(1, 0);

    return 0;
}
