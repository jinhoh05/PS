#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> fibo;
	fibo.push_back(0);
	fibo.push_back(1);
	while (true) { 
		int t = *(fibo.end() - 1) + *(fibo.end() - 2);
		if (t > 1000000000) break; 
		else fibo.push_back(t);
	}
	int n = 0; 
	cin >> n;
	while (n-- > 0) {
		int k = 0;
		cin >> k;
		int idx = fibo.size() - 1;
		stack<int> s;
		while (k != 0) {
			for (int i = idx; i > -1; i--) {
				if (k - fibo[i] >= 0) {
					s.push(fibo[i]);
					k -= fibo[i];
					idx = i - 1;
					break;
				}
			}
		}
		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}
		cout << "\n";
	}
    return 0;
}