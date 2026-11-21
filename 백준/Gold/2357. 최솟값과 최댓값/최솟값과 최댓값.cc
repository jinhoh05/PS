#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 9876543211;
int n, m, s, e;
int a[100005];
pii tree[400005];

pii update(int node, int s, int e){
    if(s == e){
		tree[node] = {a[s], a[s]};
		return tree[node];
	}

	int mid = (s + e) / 2;
	pii l = update(node * 2, s, mid);
	pii r = update(node * 2 + 1, mid + 1, e);

	tree[node].first = min(l.first, r.first);
	tree[node].second = max(l.second, r.second);

	return tree[node];
}

pii query(int node, int s, int e, int fs, int fe){
	if(e < fs || fe < s) return make_pair(INF, 0);
	if(fs <= s && e <= fe) return tree[node];

	int mid = (s + e) / 2;

	pii l = query(node * 2,  s,  mid,  fs,  fe);
    pii r = query(node * 2 + 1,  mid + 1,  e,  fs,  fe);

    pii ans;
    ans.first = min(l.first, r.first);
    ans.second = max(l.second, r.second);

	return ans;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*4;i++) tree[i].first = INF;

	for(int i=1;i<=n;i++) scanf("%d", &a[i]);

    update(1, 1, n);

	for(int i=1;i<=m;i++){
		scanf("%d %d",&s, &e);
        pii ans = query(1, 1, n, s, e);
		printf("%d %d\n", ans.first, ans.second);
	}
}
