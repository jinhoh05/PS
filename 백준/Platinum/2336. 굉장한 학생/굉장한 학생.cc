#include <bits/stdc++.h>

using namespace std;

const int MAX = 500005, INF = 2e9;

int n, ans;
int tree[4 * MAX];

struct st{
	int x, y, z;

	bool operator<(const st &t)const{
        return x < t.x;
	}

}grade[MAX];

void update(int node, int s, int e, int idx, int t){
	if(idx < s || e < idx) return;

	if(s == e){
        tree[node] = t;
        return;
	}

	int mid = (s + e) / 2;

	update(node * 2, s, mid, idx, t);
	update(node * 2 + 1, mid + 1, e, idx, t);

	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int s, int e, int fs, int fe){
	if(fe < s || e < fs) return INF;
	if(fs <= s && e <= fe) return tree[node];

	int mid = (s + e) / 2;

	return min(query(node * 2, s, mid, fs, fe), query(node * 2 + 1, mid + 1, e, fs, fe));
}

void input(){
    cin >> n;

    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            int t;
            cin >> t;

            if(i == 1) grade[t].x = j;
            else if(i == 2) grade[t].y = j;
            else grade[t].z = j;
        }
    }
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();

	sort(grade + 1, grade + n + 1);

	for(int i=1;i<=n*4;i++) tree[i] = INF;

	for(int i=1;i<=n;i++){
        if(query(1, 1, n, 1, grade[i].y) > grade[i].z) ans++;
        update(1, 1, n, grade[i].y, grade[i].z);
    }

	cout << ans;
}
