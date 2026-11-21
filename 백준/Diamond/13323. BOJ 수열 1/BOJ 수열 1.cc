#include <bits/stdc++.h>

using namespace std;
using ll = long long; 
 
int n, x;

ll ans;

priority_queue<int> pq;
 
int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		
		x -= i; 
		pq.push(x);
 
		if (!pq.empty() && pq.top() > x)
		{
			ans += pq.top() - x;
			pq.pop(); 
			pq.push(x);
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}