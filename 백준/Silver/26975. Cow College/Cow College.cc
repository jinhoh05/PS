#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
int cost[100005];

int ans;
ll money, c;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &cost[i]);

    sort(cost+1, cost+n+1);

    for(int i=n; i>0; i--){
        c = (ll)cost[i]*(n-i+1);

        if(c >= money){
            money = c;
            ans = cost[i];
        }
    }

    printf("%lld %lld", money, ans);

    return 0;
}