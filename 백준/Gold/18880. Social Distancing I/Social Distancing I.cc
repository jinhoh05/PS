#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	scanf("%d ", &N);
	vector<int>cow;
	int gap = 1000000;
	int re = 0;
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%1d", &a);
		if (a == 1)cow.push_back(i+1);
	}
	if (cow.size() > 0) {
		for (int i = 1; i < cow.size(); i++) {
			gap = min(gap, cow[i] - cow[i - 1]);
		}
		int L = 1, R = N;	
		while (L <= R) {
			int mid = (L + R) / 2;
			int cnt = 0;
			for (int i = 0; i < cow.size(); i++) {
				int p = 0;
				if (i == 0) {
					p += (cow[i] - 1) / mid;
				}
				else p = (cow[i] - cow[i - 1]) / mid > 0 ? ((cow[i] - cow[i - 1]) / mid) - 1 : 0;

				cnt += p;
			}
			cnt += (N - cow[cow.size() - 1]) / mid;
			if (cnt >= 2) {
				L = mid + 1;
				re = mid;
			}
			else {
				R = mid - 1;
			}

		}
	}
	else {
		re = N - 1;
	}
	printf("%d\n", min(re,gap));
	return 0;
}