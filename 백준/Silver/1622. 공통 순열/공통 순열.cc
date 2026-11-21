#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;
int cnt1[128], cnt2[128];

vector<int> v;

string s1, s2;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    while(getline(cin, s1) && getline(cin, s2)){
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));

		for(char c : s1) cnt1[c]++;
		for(char c : s2) cnt2[c]++;

		for(char c = 'a'; c <= 'z'; c++){
			int cnt = min(cnt1[c], cnt2[c]);
			while(cnt--) cout << c;
		}
		cout << '\n';
	}

    return 0;
}
