#include <bits/stdc++.h>

using namespace std;

int n, t;
int sz[200005], G[200005];

int find_p(int x){
    if(G[x] == x) return x;
    return G[x] = find_p(G[x]);
}

void union_find(int a, int b){
    a = find_p(a);
    b = find_p(b);

    if(a != b){
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        G[b] = a;
    }
}

int main()
{
    cin.tie(0)->ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--){
        string s1, s2;

        cin >> n;

        for(int i=0; i<200001; i++){
            sz[i] = 1;
            G[i] = i;
        }

        map<string, int> mp;
        int num=1;

        for(int i=0; i<n; i++){
            cin >> s1 >> s2;

            if(mp.count(s1) == 0) mp[s1] = num++;
            if(mp.count(s2) == 0) mp[s2] = num++;

            union_find(mp[s1], mp[s2]);

            int p1=find_p(mp[s1]);
            int p2=find_p(mp[s2]);

            cout << max(sz[p1], sz[p2]) << "\n";
        }
    }

    return 0;
}
