#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

#define f first
#define s second

int N,P;
int ans[100005];

map<int, int> m;
 
void ins(int y, int x) 
{
	auto it = prev(m.upper_bound(y));
	
	if(it->s <= x) return;
	
	it++;
	
	while(it != end(m) && it->s > x) m.erase(it++);
	
	m[y] = x;
}
 
int main()
{
	scanf("%d %d", &N, &P);
	
	m[0] = 0;
	
	vector<pair<pii, pii>> v;
	
	for(int i = 0; i < P; i++) 
	{
		pii a, b; 
		
		cin >> a.f >> a.s >> b.f >> b.s;
		
		v.push_back({a, {i, -1}});
		v.push_back({b, {i, 1}}); 
	}
	
	sort(begin(v), end(v));

	for(auto& u: v) 
	{
		if(u.s.s == -1) 
		{
			ans[u.s.f] = u.f.f + u.f.s + prev(m.upper_bound(u.f.s))->s;
		} 
		
		else 
		{
			ins(u.f.s, ans[u.s.f] - u.f.f - u.f.s);
		}
	}
	
	cout << m.rbegin()->s+2*N;
	
	return 0;
}