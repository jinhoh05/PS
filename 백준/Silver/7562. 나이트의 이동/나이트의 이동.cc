#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans, l;
int vt[305][305], check[305][305];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

vector<int> v[305];
queue<pii> q;

void bfs(int fx,int fy)
{
	while(!q.empty())
    {
		int x = q.front().first;
		int y = q.front().second;

		vt[x][y] = 1;
		q.pop();

		if(x == fx && y == fy)
		{
			cout << check[x][y] << '\n';
			return;
		}

		for(int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx >= 0 && nx < l && ny >= 0 && ny < l && vt[nx][ny] == 0)
            {
				vt[nx][ny] = 1;
				check[nx][ny] = check[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
		cin >> l;
		int sx, sy;
		int fx, fy;
		cin >> sx >> sy;
		cin >> fx >> fy;

		q.push({ sx, sy });
		bfs(fx,fy);

        for(int i=0; i<300; i++){
            for(int j=0; j<300; j++){
                check[i][j] = vt[i][j] = 0;
            }
        }

		while(!q.empty()) q.pop();
	}


    return 0;
}
