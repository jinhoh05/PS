#include <bits/stdc++.h>

using namespace std;
int n;
int tall[100005], bit[400005], ans[100005], s[100005];

void build(int node, int s, int e){
	bit[node] = e - s + 1;
	if(s == e) return;
	build(node * 2, s, (s + e) / 2);
	build(node * 2 + 1, (s + e) / 2 + 1, e);
}

void update(int node, int s, int e, int idx, int tg){
	bit[node]--;
	if(s == e){
		ans[tg] = tall[s];
		return;
	}
	
	int lch = node * 2, rch = lch + 1;
	int m = (s + e) / 2;
	
	if(bit[lch] > idx) update(lch, s, m, idx, tg);
	else update(rch, m + 1, e, idx - bit[lch], tg);
}

const int INF = 9876543211;
int query(int node, int s, int e, int fs, int fe){
	if(e < fs || fe < s) return -INF;
	if(fs <= s && e <= fe) return bit[node];
	return max(query(node * 2, s, (s + e) / 2, fs, fe), query(node * 2 + 1, (s + e) / 2 + 1, e, fs, fe));
}

void input(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &tall[i]);
	for(int i=1;i<=n;i++) scanf("%d", &s[i]);
}

int main()
{
	input();

	sort(tall + 1, tall + n + 1);

	build(1, 1, n);

	for(int i=n;i>=1;i--) update(1, 1, n, s[i], i);

	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	
    return 0;
}