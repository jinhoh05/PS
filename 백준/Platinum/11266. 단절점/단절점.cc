#include <bits/stdc++.h>

#define MAXV 10002

using namespace std;

int v, e;
vector<vector<int>> adj;
int discovered[MAXV];
bool visit[MAXV];
int cnt = 0;
bool cutPoint[MAXV];

int dfs(int here, bool isRoot)
{
	discovered[here] = ++cnt;
	int child = 0;
	int ret = discovered[here];

	for (int i = 0; i < (int)adj[here].size(); i++)
	{
		int there = adj[here][i];

		if (discovered[there] == 0)
		{
			child++;

			int subtree = dfs(there, false);

			//절단점
			if (!isRoot && subtree >= discovered[here])
			{
				cutPoint[here] = true;
			}

			ret = min(ret, subtree);
		}

		//역방향 간선일때
		else
		{
			ret = min(ret, discovered[there]);
		}
	}

	//루트일때
	if (isRoot && child > 1)
		cutPoint[here] = true;

	return ret;
}


int main()
{
	cin >> v >> e;
	adj.resize(v + 2);

	int first, second;
	int maxNode = 0;
	for (int i = 0; i < e; i++)
	{
		cin >> first >> second;
		adj[first].push_back(second);
		adj[second].push_back(first);
		
		maxNode = max(maxNode, first);
		maxNode = max(maxNode, second);
	}

	for (int i = 1; i <= maxNode; i++)
	{
		if(discovered[i] == 0)
			dfs(i, true);
	}

	vector<int > result;
	for (int i = 1; i <= maxNode; i++)
		if (cutPoint[i] == true)
			result.push_back(i);

	cout << result.size() << '\n';

	for (auto& ele : result)
		cout << ele << ' ';

	return 0;
}