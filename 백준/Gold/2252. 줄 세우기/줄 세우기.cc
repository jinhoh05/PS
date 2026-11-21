#include <bits/stdc++.h>

using namespace std;
int n, m;
int point[32005];
queue<int> q;
vector<int> v[32005];

void push(int x){
    for(int u : v[x]){
        point[u]--;
        if(point[u] == 0) q.push(u);
    }
}

void topol(){
    while(!q.empty()){
		int t = q.front();
		q.pop();

		printf("%d ", t);

		push(t);
	}
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        point[b]++;
        v[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(point[i] == 0) q.push(i);
    }

    topol();

    return 0;
}
