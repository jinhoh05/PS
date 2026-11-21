#include<bits/stdc++.h>

using namespace std;

int n, m, ans;
int cow[205], vt[205];

vector<int> v[205];

int cattle(int x){
    if(vt[x]) return 0;
    vt[x] = 1;

    for(int u : v[x]){
        if(!cow[u] || cattle(cow[u])){
            cow[u] = x;
            return 1;
        }
    }

    return 0;
}

void input(){
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        int a, b;

        cin >> a;

        while(a--){
            int b;
            cin >> b;
            v[i].push_back(b);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();


    for(int i=1;i<=n;i++){
        if(cattle(i)) ans++;
        memset(vt, 0, sizeof(vt));
    }

    cout << ans;
}
