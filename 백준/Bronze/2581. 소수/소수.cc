#include <bits/stdc++.h>

using namespace std;

int n, m;
int prime[10005];

void eratos(){
    prime[0] = prime[1] = 1;

    for(int i=2;i<=m;i++){
        if(prime[i] == 0){
            for(int j=i*i;j<=m;j+=i) prime[j] = 1;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    eratos();

    int hap = 0, MIN = 1e9;

    for(int i=n;i<=m;i++){
        if(prime[i] == 0){
            MIN = min(MIN, i);
            hap += i;
        }
    }

    if(MIN == 1e9) cout << "-1";

    else cout << hap << "\n" << MIN;

    return 0;
}
