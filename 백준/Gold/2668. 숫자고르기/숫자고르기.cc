#include <bits/stdc++.h>

using namespace std;

int n;
int arr[105];
bool vt[101];

set<int> answer;

bool flag;

void dfs(int st,int num) {	
	if (vt[num]) {
		if (st == num) {
				flag = true;
				answer.insert(num);
		}
		return;
	}
	
	vt[num] = true;
	dfs(st,arr[num]);
	
	if (flag) {
		answer.insert(num);
		answer.insert(arr[num]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 1; i <= n; i++) {
		vt[i] = true;
		dfs(i, arr[i]);
		memset(vt, false, 105);
		flag = false;
	}
	
	cout << answer.size() << '\n';
	for (int u : answer) {
		cout << u << '\n';
	}
	
	return 0;
}