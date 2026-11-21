#include <bits/stdc++.h>

using namespace std;

int n, m;
int seq[10], vt[10];

void dfs(int cnt){
    if(cnt == m){
        for(int i=0;i<m;i++) cout << seq[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1;i<=n;i++){
        if(!vt[i]){
            vt[i] = 1;
            seq[cnt] = i;
            dfs(cnt + 1);
            vt[i] = 0;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    dfs(0);

    return 0;
}
