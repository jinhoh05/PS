#include <bits/stdc++.h>

using namespace std;
int n,q,tree_big[200005],tree_small[200005];
const int INF=987654321;

void update_big(int node, int s, int e, int idx, int t){
	if(idx < s || idx > e) return;
	if(s == e){
		tree_big[node] = t;
		return;
	}

	update_big(node*2, s, (s+e)/2, idx, t);
	update_big(node*2+1, (s+e)/2+1, e, idx, t);

	tree_big[node]=max(tree_big[node*2], tree_big[node*2+1]);
}

void update_small(int node, int s, int e, int idx, int t){
	if(idx < s || idx > e) return;
	if(s == e){
		tree_small[node] = t;
		return;
	}

	update_small(node*2, s, (s+e)/2, idx, t);
	update_small(node*2+1, (s+e)/2+1, e, idx, t);

	tree_small[node]=min(tree_small[node*2], tree_small[node*2+1]);
}

int query_big(int node, int s, int e, int fs, int fe){
	if(e < fs || fe < s) return 0;
	if(fs <= s && e <= fe) return tree_big[node];
	return max(query_big(node*2, s, (s+e)/2, fs, fe), query_big(node*2+1, (s+e)/2+1, e, fs, fe));
}

int query_small(int node, int s, int e, int fs, int fe){
	if(e < fs || fe < s) return INF;
	if(fs <= s && e <= fe) return tree_small[node];
	return min(query_small(node*2, s, (s+e)/2, fs, fe), query_small(node*2+1, (s+e)/2+1, e, fs, fe));
}

int main()
{
	scanf("%d %d",&n,&q);

	for(int i=1;i<=n*4;i++){
		tree_big[i]=-INF;
		tree_small[i]=INF;
	}


	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		update_big(1,1,n,i,a);
		update_small(1,1,n,i,a);
	}

	for(int i=1;i<=q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",query_big(1,1,n,a,b) - query_small(1,1,n,a,b));
	}

    return 0;
}