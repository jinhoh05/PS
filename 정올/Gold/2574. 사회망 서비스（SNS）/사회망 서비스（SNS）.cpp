#include <bits/stdc++.h>

using namespace std;

/// 그리디 알고리즘

/// 1. leaf node는 ea일 필요가 없다
/// 2. parent node는 child 중에 하나라도 ea가 아닌 것이 있다 -> ea로
///                 child 모두가 ea라면 -> not ea로

const int MAX = 1000005;

int n, ans;
int child[MAX];
int urr[MAX], vrr[MAX];

vector<int> v[MAX];

int dfs(int x, int p){
    int ea = 0;

    for(int u : v[x]){
        if(u == p) continue;
        if(!dfs(u, x)) ea = 1;
    }

    ans += ea;

    return ea;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n-1;i++){
        cin >> urr[i] >> vrr[i];

        child[urr[i]]++;
        child[vrr[i]]++;
    }

    for(int i=1;i<=n;i++) v[i].reserve(child[i]);

    for(int i=1;i<=n-1;i++){
        v[urr[i]].push_back(vrr[i]);
        v[vrr[i]].push_back(urr[i]);
    }

    dfs(1, 1);

    cout << ans;

    return 0;
}