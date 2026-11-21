#include <algorithm>
#include <iostream>
using namespace std;

//cnt[n][i]: 배열 A의 크기가 n일 때 B[i] - T[i]
int cnt[5001][5001] = { 0 };
//psum[n][i]: 배열 A의 크기가 n일 때 cnt[0] ~ cnt[i]까지의 부분합
int psum[5001][5001] = { 0 };

void binAdd(int n, int s, int e, int add) {
	if (s > e) return;

	int mid = (s + e) / 2;
	cnt[n][mid] += add++;

	binAdd(n, s, mid - 1, add);
	binAdd(n, mid + 1, e, add);
}

void terSub(int n, int s, int e, int sub) {
	if (s > e) return;

	if (s == e) {
		cnt[n][s] -= sub;
		return;
	}

	int t1 = s + (e - s) / 3;
	int t2 = e - (e - s) / 3;

	cnt[n][t1] -= sub++;
	cnt[n][t2] -= sub++;

	terSub(n, s, t1 - 1, sub);
	terSub(n, t1 + 1, t2 - 1, sub);
	terSub(n, t2 + 1, e, sub);
}

void getPrefixSum() {

	//배열 A의 크기 1 ~ 5000일 때 cnt의 부분합 계산
	for (int n = 1; n <= 5000; ++n) {

		binAdd(n, 0, n - 1, 0);
		terSub(n, 0, n - 1, 0);
		
		psum[n][0] = cnt[n][0];
		for (int i = 1; i <=  n; ++i) 
			psum[n][i] = psum[n][i - 1] + cnt[n][i];
	}

	return;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	getPrefixSum();

	int Q;
	cin >> Q;
	while (Q--) {
		int N, S, E;
		cin >> N >> S >> E;

		if (S == 0) cout << -psum[N][E] << "\n";
		else cout << -(psum[N][E] - psum[N][S-1]) << "\n";

	}
	return 0;
}