#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100005], tree[400005];

int update(int node, int s, int e, int idx, int val){
    if(e < idx || idx < s) return tree[node];

    if(s == e) return tree[node] = val;

    int mid = (s + e) / 2;
    int l = update(node * 2, s, mid, idx, val);
    int r = update(node * 2 + 1, mid + 1, e, idx, val);

    return tree[node] = l * r;
}

int query(int node, int s, int e, int fs, int fe){
    if(e < fs || fe < s) return 1;

    if(fs <= s && e <= fe) return tree[node];

    int mid = (s + e) / 2;
    int l = query(node * 2, s, mid, fs, fe);
    int r = query(node * 2 + 1, mid + 1, e, fs, fe);

    return l * r;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while(cin >> n >> k){
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;

            if(x > 0) update(1, 1, n, i, 1);

            else if(!x) update(1, 1, n, i, 0);

            else update(1, 1, n, i, -1);
        }

        char x;
        int y, z;

        for(int i=0;i<k;i++){
            cin >> x >> y >> z;

            if(x == 'C'){
                if(z > 0) update(1, 1, n, y, 1);

                else if(!z) update(1, 1, n, y, 0);

                else update(1, 1, n, y, -1);
            }

            else{
                int val = query(1, 1, n, y, z);

                if(!val) cout << 0;
                else cout << (val > 0 ? '+' : '-');
            }
        }

        cout << "\n";
    }

    return 0;
}
