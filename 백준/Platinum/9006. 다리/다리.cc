#include<bits/stdc++.h>

using namespace std;

const int SZ=2000005;

typedef long long ll;

pair<ll,int> arr[SZ];

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		for(int i=0;i<n;i++){
			ll x; cin>>x;
			arr[i]={x,m};
		}
		for(int i=n;i<n+m;i++){
			ll x; cin>>x;
			arr[i]={x,n};
		}
		sort(arr,arr+n+m);
		ll xx=-(ll)n*(ll)m;
		for(int i=0;i<n+m;i++){
			xx+=arr[i].second;
			if(xx>=0){
				cout<<fixed; cout.precision(1);
				cout<<double(arr[i].first)<<'\n';
				break;
			}
		}
	}
	return 0;
}