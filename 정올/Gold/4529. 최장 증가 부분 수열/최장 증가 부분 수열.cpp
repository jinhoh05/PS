#include <bits/stdc++.h>

using namespace std;
int n, num;
int lis[2000005];

struct data{
	int x, lev;
	bool operator<(const data &t){
		if(x == t.x) return lev > t.lev;
		return x < t.x;
	}
}seg[500005];

void update(int node, int s, int e, int idx, int t){
	if(idx < s || idx > e) return;
	if(s == e){
		lis[node] = t;
		return;
	}

	update(node * 2, s, (s + e) / 2, idx, t);
	update(node * 2 + 1, (s + e) / 2 + 1, e, idx, t);

	lis[node] = max(lis[node * 2], lis[node * 2 + 1]);
}

const int INF = 9876543211;
int query(int node, int s, int e, int fs, int fe){
	if(e < fs || fe < s) return -INF;
	if(fs <= s && e <= fe) return lis[node];
	return max(query(node * 2, s, (s + e) / 2, fs, fe), query(node * 2 + 1, (s + e) / 2 + 1, e, fs, fe));
}

void LIS(){
	sort(seg + 1, seg + n + 1);

	for(int i=1;i<=n;i++){
		int maximum = query(1, 1, n, 1, seg[i].lev - 1) + 1;
		if(maximum < 0) maximum = 1;
		update(1, 1, n, seg[i].lev, maximum);
	}

	printf("%d", query(1, 1, n, 1, n));
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		seg[i] = {num, i};
	}

	LIS();

    return 0;
}