#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int LN = 1e6 + 5;

int n;
int a, b, c;

ll val;
ll p[LN], DP[LN], s[LN];

struct Line{

    ll a, b;

    ll getY(ll x){
        return a * x + b;
    }

}line[LN];

ll getX(Line s1, Line s2, Line s3){
    ll a1 = s1.a, b1 = s1.b;
    ll a2 = s2.a, b2 = s2.b;
    ll a3 = s3.a, b3 = s3.b;

    return (a2 - a1) * (b1 - b3) < (b1 - b2) * (a3 - a1);
}

void dynamic(){

    int pt=1, cnt=0;

    line[++cnt] = {0, 0};

    for(int i=1; i<=n; i++){
        while(pt<cnt && line[pt].getY(s[i])<line[pt+1].getY(s[i])) pt++;
        
        DP[i] = a*s[i]*s[i] + b*s[i] + c + line[pt].getY(s[i]);

        Line tmp = {-2*a*s[i], DP[i] + a*s[i]*s[i] - b*s[i]};
        while(cnt>1 && getX(line[cnt-1], line[cnt], tmp)) cnt--;
        line[++cnt] = tmp;
    }
}

int main()
{
    scanf("%d", &n);
    scanf("%d %d %d", &a, &b, &c);

    for(int i=1; i<=n; i++){
        scanf("%lld", &p[i]);
        s[i] = p[i] + s[i-1];
    }

    dynamic();

    printf("%lld", DP[n]);

    return 0;
}
