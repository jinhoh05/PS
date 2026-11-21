#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
typedef long long ll;
vector<string>arr;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k; cin >> n >> m >> k;
	ll res = 0;
	for (int i = 0; i < k; i++) {
		string x; cin >> x;
		arr.push_back(x);
	}
	
	stack<int>st;
	for (int i = 0; i < n; i++) {
		char x; cin >> x;
		st.push(x - 'A');
	}

	int minn = m - 1, maxx = m - 1;
	int now = st.top();
	st.pop();
	for (int i = m - 2; i >= 0; i--) {
		if (arr[now][i] == 'U')
			break;
		minn = i;
	}
	res += maxx - minn + 1;

	while (!st.empty()) {
		bool flag = false;
		now = st.top();
		st.pop();

		for (int i = maxx; i >= 0; i--) {
			if (arr[now][i] == 'U') {
				maxx = i;
				break;
			}
			if (i == 0)
				flag = true;
		}
		if (flag) break;

		for (int i = minn - 1; i >= 0; i--) {
			if (minn == 0) break;
			if (arr[now][i] == 'U') {
				if (i + 1 > maxx) {
					flag = true;
					break;
				}
				else
					minn = i + 1;
				break;
			}
			if (i == 0)
				minn = 0;
		}
		if (flag) break;

		res += maxx - minn + 1;
	}
	cout << res;
	return 0;
}