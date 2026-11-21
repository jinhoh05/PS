#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;
int d, k, c;
int sushi[30005], check[30005];

vector<int> v;

int main(){

    scanf("%d %d %d %d", &n, &d, &k, &c);
    for(int i=0; i<n; i++){
        scanf("%d", &sushi[i]);
    }

    for(int i=0; i<n; i++){
        int coupon=1;
        int flag=0;
        for(int j=i; j<i+k; j++){
            if(check[sushi[j%n]]) flag++;
            else check[sushi[j%n]]=1;

            if(sushi[j%n] == c) coupon=0;
        }

        ans = max(ans, k-flag+coupon);
        memset(check, 0, sizeof(check));
    }

    printf("%d", ans);

    return 0;
}
