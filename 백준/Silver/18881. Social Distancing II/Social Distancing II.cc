#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>>cow;
	vector<int>cand;
	for (int i = 0; i < N; i++) {
		int x, s;
		cin >> x >> s;
		cow.push_back({ x,s });
	}
	sort(cow.begin(), cow.end());
	int R = 1e9;
	for (int i = 0; i < cow.size(); i++) {
		if (cow[i].second == 0) {
			if (i - 1 > 0&&cow[i-1].second==1) {
				R = min(R, cow[i].first - cow[i - 1].first);
			}
			if (i + 1 < cow.size()&&cow[i+1].second==1) {
				R = min(R, cow[i + 1].first - cow[i].first);
			}
		}
		if (cow[i].second == 1)cand.push_back(cow[i].first);
	}
	R--;
	int re = 0;
	for (int i = 0; i <cand.size()-1; i++) {
		if (cand[i + 1] - cand[i] > R)re++;
	}
	printf("%d\n", re+1);
    
	return 0;
}