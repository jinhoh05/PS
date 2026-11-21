	#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
 
int n, m;
vector<int> v[1001];
bool visited[1001];
int work[1001];
int ret = 0;
bool dfs(int from)
{
	//if(visited[from]) return false;
 
	visited[from] = true;
 
	int len = v[from].size();
	for (int i = 0; i < len; i++)
	{
		int to = v[from][i];
        //if(work[to] == 0 ||dfs(work[to]))
		if (work[to] == 0 || !visited[work[to]] && dfs(work[to]))
		{
			work[to] = from;
			return true;
		}
	}
	return false;
}
int main(void)
{
	scanf("%d %d", &n, &m);
 
	for (int i = 1; i <= n; i++)
	{
		int m;
		scanf("%d", &m);
		for (int j = 0;j< m; j++)
		{
			int can;
			scanf("%d", &can);
			v[i].push_back(can);
			
		}
	}
	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		if (dfs(i))
			ret++;
	}
	printf("%d", ret);
	return 0;
}