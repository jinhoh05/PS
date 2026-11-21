#include <bits/stdc++.h>
using namespace std;
vector<int> ans[1010];
vector<pair<int,int>> V;
int ck[1010];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	for(int i = 0;i<k;i++){
		int a; cin >> a;
		for(int j = 0;j<a;j++){
			int b; cin >> b;
			V.push_back({b,i});
		}
	}
	int num = 1;
	sort(V.begin(),V.end());
	for(int d = 0;d<n;d++){
		for(int i = 0;i<V.size();i++) if(!ck[i]) {
			if(num - ans[V[i].second].size()-1 -V[i].first== 0){
				ans[V[i].second].push_back(num++);
				ck[i] = 1;
				break;
			}
		}
	}
	for(int i = 0;i<k;i++){
		sort(ans[i].begin(),ans[i].end());
		for(auto j : ans[i]) cout << j << ' ';
		cout << '\n';
	}
}