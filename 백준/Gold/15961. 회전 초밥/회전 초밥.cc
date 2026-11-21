#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans, cnt;
int d, k, c;
int sushi[3003005], check[3005];

vector<int> v;

int main(){

    scanf("%d %d %d %d", &n, &d, &k, &c);
    for(int i=0; i<n; i++){
        scanf("%d", &sushi[i]);
    }

    for(int i=0; i<k; i++){
        sushi[n+i] = sushi[i];
        if(!check[sushi[i]]++) cnt++;
    }

    ans=cnt;
    for(int i=k; i<n+k; i++){
        if(--check[sushi[i-k]] == 0) cnt--;
        if(!check[sushi[i]]++) cnt++;
        ans = max(ans, cnt + (check[c] == 0));
    }

    printf("%d", ans);

    return 0;
}
