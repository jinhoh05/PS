	#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
 
const int prime_size = 2001, max_size=51;
bool isprime[prime_size];
int n;
vector<vector<int>> adj;
vector<int> value;
 
bool visited[max_size],s[max_size];
int p[max_size];
 
 
void get_prime()
{
	fill(isprime, isprime + prime_size, true);
 
	isprime[0] = isprime[1] = false;
	int limit = (int)sqrt(prime_size);
	for (int i = 2; i < limit; ++i)
	{
		if (isprime[i] == true) {
			for (int iter = 2; i*iter < prime_size; iter++)
				isprime[i*iter] = false;
		}
	}
 
	return;
}
bool dfs(int cur)
{
	if (visited[cur] )
		return false;
	visited[cur] = true;
 
	int len = adj[cur].size();
	for (int i = 0; i < len; ++i)
	{
		int next = adj[cur][i];
 
		if (p[next] == -1 || dfs(p[next]))
		{
			p[next] = cur;
			s[cur] = true;
			visited[next] = true; //for bidirectional matching
 
			p[cur] = next;
			s[next] = true;
			return true;
		}
	}
	return false;
}
 
int main()
{
	get_prime();
 
	scanf("%d", &n);
	value.resize(n + 1);
	adj.resize(n + 1);
 
	for (int i = 1; i <= n; ++i)
		scanf("%d", &value[i]);
 
	//sorting
	sort(value.begin() + 2, value.end());
	
	//make graph
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if(i!=j)
				if (isprime[value[i] + value[j]])
					adj[i].push_back(j);
			
	//bipartite matching
	vector <int> ans;
	int len = adj[1].size();
	for (int iter = 0; iter < len; ++iter)
	{
		int chk = 2;	//because I select one pair.
		fill(p, p + max_size, -1);
		fill(s, s + max_size, false);
 
		int matched = adj[1][iter];
 
		for (int i = 1; i <= n; ++i)
		{
			if (s[i])
				continue;
			fill(visited, visited + max_size, false);
 
			visited[1] = visited[matched] = true;
			p[matched] = 1;
			s[1] = true;
			p[1] = matched;
			s[matched] = true;
 
			if (dfs(i))
				chk+=2;
		}
		if (chk == n)
			ans.push_back(value[matched]);
	}
	
 
	len = ans.size();
	if (len == 0)
		printf("-1");
	else
		for (int i = 0; i < len; ++i)
			printf("%d ", ans[i]);
 
	return 0;
}