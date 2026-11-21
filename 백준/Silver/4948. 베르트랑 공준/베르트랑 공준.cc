#include <bits/stdc++.h>

using namespace std;

int n;
int prime[250000];

void eratos(){
    prime[1] = 1;

    for(int i=2;i*i<=250000;i++){
        if(!prime[i]){
            for(int j=i*i;j<=250000;j+=i) prime[j] = 1;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    eratos();

    while(1){
        cin >> n;

        if(!n) break;

        int cnt = 0;
        for(int i=n+1;i<=n*2;i++){
            if(!prime[i]) cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}
