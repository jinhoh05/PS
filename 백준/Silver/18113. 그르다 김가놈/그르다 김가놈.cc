#include <bits/stdc++.h>

using namespace std;

/*
    cin 쓰고 싶을때
    fastio;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
*/

int n, k, m;
int bab, ans = -1;
int gim[1000005];

int cut(int x) {
	int cnt = 0;

	for(int i=1;i<=n;i++){
		if(gim[i] >= 2 * k) cnt += (gim[i] - 2 * k) / x;

		else if(gim[i] < 2 * k && gim[i] > k) cnt += (gim[i] - k) / x;
	}

	return cnt >= m ? 1 : 0;
}

void binary_Search(int l, int r) {
	if(l > r) return;

	int mid = (l + r) / 2;

	if(cut(mid)){
		ans = max(ans, mid);
		binary_Search(mid + 1, r);
	}

	else binary_Search(l, mid - 1);
}

int main()
{
	scanf("%d %d %d", &n, &k, &m);

	for(int i=1;i<=n;i++) {
		scanf("%d", &gim[i]);
		bab = max(bab, gim[i]);
	}

	binary_Search(1, bab - k);

	printf("%d", ans);

	return 0;
}
